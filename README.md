# SDK Reference App

The SDK Reference App demonstrates an end-to-end integration of the TapPoint&reg; SDK into an example application. It shows how to:

1. Connect to TapPoint&reg; (Authenticate)
2. Download trigger information (Synchronise)
3. Detect trigger events and respond to them in the application (Monitor)
4. Send analytics information to TapPoint&reg; (Reporting)

Use the Reference App as a guide for integrating TapPoint&reg; into your own projects.
SDK reference documentation is also available on the [TapPoint developer portal](http://developer.tappoint.com/).

## Getting Started

### Prerequisites

The application requires Xcode 6.1.

To get trigger events working, you will need either a physical Bluetooth beacon, or use an iPhone as a virtual beacon.

There are ready-made apps in the iTunes app store that can act as virtual beacons. That's the easiest option to get started.

If you do want to dive deeper, then Apple's [AirLocate sample](https://developer.apple.com/library/ios/samplecode/AirLocate/Introduction/Intro.html) sample code shows how to build a virtual beacon.

Whether you have a virtual or a physical beacon, configure it as follows:

| Property | Value                                  |
| :------: | -----                                  |
| UUID     | `50726f78-616d-4142-8c45-426561636f6e` |
| Major    | `1`                                    |
| Minor    | `1` for test beacon one <br>or `2` for test beacon two <br> or `3` for test beacon three |

It doesn't matter if the letters in the UUID are in upper or lower case.

### Guided tour of the code

The project is configured with the framework prerequisites as described in the [Getting Started Guide](http://developer.tappoint.com/ios/quick-start).
The first thing the reference app does when working with the TapPoint&reg; SDK is to Authenticate itself with TapPoint&reg;.
The `AppDelegate.m` file imports the TapPoint&reg; SDK header file.
In its `application:didFinishLaunchingWithOptions:` method, we call:

```
[[PRXAuthentication sharedAuthenticationManager] authenticateWithAppName:@"sdk_reference_app" success:^{
     NSLog(@"TapPoint: Successfuly authenticated with TapPoint.");
        ...
} ^failure:^(NSError *error) {
        ...
}];
```
If authentication succeeds, then the code inside the success block happens, otherwise the failure block is called.

#### Synchronisation

The TapPoint&reg; server has already been configured with 'IN' and 'OUT' triggers for the 3 reference app beacons - 6 triggers in total.
Those triggers have to be downloaded (synchronised) onto the device. The first time the application launches there won't be any triggers on the device, and it will download all of them from the server. The next time though, unless the data on TapPoint&reg; has changed, the application will already be up to date and no new triggers will be downloaded during the synchronisation.

Because you have to authenticate with TapPoint&reg; first, we call synchronise in the success block of authenticate:

```
[[PRXSynchronisation sharedSynchronisationManager] synchroniseWithSuccess:^(PRXSyncResult *result) {
    NSLog(@"TapPoint: Synchronised with TapPoint.");
    ...
} failure:^(NSError *error) {
    NSLog(@"TapPoint: Unable to synchronise with TapPoint.");
    ...
}];         
```

### Monitoring for trigger events

Once the triggers have been successfully downloaded, we can begin to monitor for beacons.

We register the `appDelegate` with the default `NSNotificationCenter`, asking for our `processDetectedTrigger:` method to be called whenever a trigger is detected (and a `PRXTriggersDetectedNotification` is broadcast):

``` 
[[NSNotificationCenter defaultCenter] addObserver:self
                                         selector:@selector(processDetectedTrigger:)
                                             name:PRXTriggersDetectedNotification
                                           object:nil];
```

Then we call startMonitoring:

```
[[PRXTriggers sharedTriggersManager] startMonitoring];
```

### Reporting trigger events

When the `appDelegate` detects a trigger event, it will log it with `NSLog` (not recommended for a real application!).
To report that the user was notified about the trigger, the `processDetectedTrigger:` method calls the reporting SDK to report that a trigger-related event has occurred:

```
PRXTrigger *trigger = [notification.userInfo objectForKey:PRXDetectedTriggerNotificationKeyForTrigger];
[[PRXReporting sharedReportingManager] reportTriggerEvent:PRXTriggerEventTypeUserNotified triggerID:trigger.identifier];
```

A better example requires some user interaction, such as displaying a visual notification to the user, or responding to taps on those visual notifications. The `BeaconEventsTableViewController` class shows that in more detail.

### Using trigger payload data

In the `BeaconEventsTableViewController` we show a table view, with a row for each beacon event detected. Each table view cell shows a title, a subtitle, and an icon representing which beacon triggered the event.

The title, subtitle and the name of the image to display are taken from the trigger payload that is defined on TapPoint&reg;. The method `tableView:cellForRowAtIndexPath:` shows how to take a `NSNotification` object and extract a `PRXTrigger` object from its `userInfo` dictionary:

```
PRXTrigger *trigger = notification.userInfo[PRXDetectedTriggerNotificationKeyForTrigger];
NSDictionary *payloadData = trigger.payload[@"data"];
```

The `payloadData` dictionary then contains the custom payload data that was defined on TapPoint&reg;.

### Reporting other events

There are two kinds of events that we report. One is when a visual notification is displayed to the user - in this case that's when we add a new row to our table - that's `PRXTriggerEventTypeUserNotified`, and for the reference app, this is actually reported by the `AppDelegate`. The other kind of event is when the user taps on an item in the table - that's `PRXTriggerEventTypeUserSelected`. The `tableView:didSelectRowAtIndexPath:` method shows how to report a 'user selected' event type.

### Running the application

Build and run the application on a device - the simulator doesn't support iBeacons. Then get ready with your physical or virtual beacons.
You don't have to move - simply turn a bluetooth beacon on or off to simulate entering into or leaving a beacon's range. You should see beacon events appear in the table view and log statements in the console.
