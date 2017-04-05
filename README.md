# TapPoint SDK

The TapPoint&reg; SDK enables you to interact with the TapPoint&reg; beacon network easily, providing you with the ability to:

1. Connect to TapPoint&reg; (Authenticate)
2. Download trigger information (Synchronise)
3. Detect trigger events and respond to them in the application (Monitor)
4. Send analytics information to TapPoint&reg; (Reporting)

TapPoint&reg; SDK reference documentation is also available on the [TapPoint developer portal](http://developer.tappoint.com/).

## Getting Started

### Prerequisites

To get trigger events working, you will need either a physical Bluetooth beacon, or use an iPhone as a virtual beacon.

There are ready-made apps in the iTunes app store that can act as virtual beacons, including our [Virtual Beacon app](https://appsto.re/gb/aCMr7.i). That's the easiest option to get started.

If you do want to dive deeper, then Apple's [AirLocate sample](https://developer.apple.com/library/ios/samplecode/AirLocate/Introduction/Intro.html) sample code shows how to build a virtual beacon.

Whether you have a virtual or a physical beacon, configure it as follows:

| Property | Value                                  |
| :------: | -----                                  |
| UUID     | `50726f78-616d-4142-8c45-426561636f6e` |
| Major    | `1`                                    |
| Minor    | `1` for test beacon one <br>or `2` for test beacon two <br> or `3` for test beacon three |

It doesn't matter if the letters in the UUID are in upper or lower case.
These beacons will trigger if registering with the app name of: sdk_reference_app (see the section: Authenticating with TapPoint).

## Guided tour of using the TapPoint&reg; SDK

This walkthrough is also available from our portal [Getting Started Guide](http://developer.tappoint.com/ios/quick-start).

### Prerequisites

In Xcode, make sure the following conditions are met:
* Deployment target is set to iOS 8.0 or higher
* SDK version is set to iOS 8.0 SDK or higher
* [CFBundleDisplayName](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CoreFoundationKeys.html#//apple_ref/doc/uid/20001431-110725) has been set with a valid value. To do this, navigate to your application's main target, select the *Info* tab, add a new row with the key set as *Bundle display name*

### iOS 8 Location Services

TapPoint&reg; SDK uses location services to find out information about the user's current location. As of iOS 8, when using location services, you are required to add a string value for the [NSLocationAlwaysUsageDescription](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW18) within your application's `.plist` file. iOS uses this string to display a message when asking the user for permissions to use their location information.

### Installing the SDK

The TapPoint&reg; SDK uses CocoaPods. In order to use the TapPoint&reg; SDK, add the following to your podfile: 

```
pod 'TapPointSDK', '~> 3.2.0'
```

As the TapPoint&reg; SDK uses categories, the final stage of installation requires you to add a linker flag to the main target of your application. This can be done by navigating to the *Build Settings* tab, then finding Other Linker Flags. Then add **-ObjC** as a linker flag, if it is not already there.

### Using the SDK

The TapPoint&reg; SDK has a set of APIs that you can use to:

1. Authenticate your application with TapPoint
2. Download Triggers (campaign data and campaign Payload)
3. Start monitoring for beacons

Several of these APIs provide relevant and useful feedback via blocks. In the case where an API provides a failure callback, you can inspect an [NSError](https://developer.apple.com/library/ios/documentation/Cocoa/Reference/Foundation/Classes/NSError_Class/index.html) object to find out more information on the reason for failure. In the case where the API does not provide a callback for failure, a log message will be provided to the debug console within your Xcode development environment, or using Console.app.

You can import the `<TapPointSDK/TapPointSDK.h>` header to use any of the TapPoint SDK APIs.

#### Authenticating with TapPoint

Authenticate with TapPoint by passing the application name (provided by Proxama) as a parameter to the `authenticateWithAppName:success:failure:` method.

It is important that you call this API in your AppDelegate's `application:didFinishLaunchingWithOptions:` method.

```
[[PRXAuthentication sharedAuthenticationManager] authenticateWithAppName:@"sdk_reference_app" success:^{
    // The application successfully authenticated with TapPoint
} failure:^(NSError *error) {
    // The application failed to authenticate with TapPoint
}];
```

This API should be called every time your application launches to ensure that other APIs being called can be used.

#### Synchronising Triggers

One of the advantages of using TapPoint&reg; SDK is that it delivers campaign data even in areas of no connectivity (underground, stadiums). Triggers, which encapsulate campaign data, are required to be synced down to the SDK prior to a campaign starting.

For testing purposes we've sent 3 physical beacons to help you with your integration (or if you have an iOS device you can use our [Virtual Beacon app](https://appsto.re/gb/aCMr7.i) to simulate a beacon). To add campaign data to these Triggers use the [TapPoint Beacon Payload Editor](https://connect.tappoint.com/payload/) tool. Once saved, perform a sync:

```
[[PRXSynchronisation sharedSynchronisationManager] synchroniseWithSuccess:^(PRXSyncResult *result) {
    // The application synchronised successfully with TapPoint
} failure:^(NSError *error) {
    // The application failed to synchronise with TapPoint
}];
```

Upon successful synchronisation with TapPoint, the success block provides a [PRXSyncResult](http://developer.tappoint.com/ios/api-docs/Classes/PRXSyncResult.html) object that contains arrays of both Triggers that have been added, and Triggers that have been removed during this synchronisation. This is purely for your information, the Triggers will be automatically stored by the TapPoint&reg; SDK. In the instance where synchronisation has failed, you can inspect the [NSError](https://developer.apple.com/library/ios/documentation/Cocoa/Reference/Foundation/Classes/NSError_Class/index.html) object to find out the reason for failure where both an error code and error description is provided.

##### Synchronisation Strategy

Once Triggers have been successfully synced onto the device, you do not have to sync again, unless the Trigger data on TapPoint has changed (e.g. a new campaign has been created). It is up to you to decide when and how often a sync should take place.

A simple syncing strategy would be to perform a synchronisation with TapPoint every time your application launches.

#### Trigger Monitoring

Notifications about Trigger events are emitted by the default [NSNotificationCenter](https://developer.apple.com/library/ios/documentation/Cocoa/Reference/Foundation/Classes/NSNotificationCenter_Class/index.html), and in order to listen to these events you need to add yourself an as observer to [NSNotificationCenter](https://developer.apple.com/library/ios/documentation/Cocoa/Reference/Foundation/Classes/NSNotificationCenter_Class/index.html) notification events named [PRXTriggersDetectedNotification](http://developer.tappoint.com/ios/api-docs/Classes/PRXTriggers.html) and provide a callback message (e.g. `triggerDetected:`) which will be sent when a Trigger event is fired.

```
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(triggerDetected:) name:PRXTriggersDetectedNotification object:nil];
```

Call `startMonitoring` to begin scanning for Triggers. Notifications will then be generated in response to Trigger events.

```
[[PRXTriggers sharedTriggersManager] startMonitoring];
```

**NOTE:** If you are monitoring for Trigger events, any new Triggers subsequently added will automatically be monitored.

**NOTE:** Trigger events can only be detected and notifications sent when the user has bluetooth/location services turned on, but should the user disable bluetooth/location services, they will automatically start being detected and sending notifications once they are turned on again. There is no need to call `startMonitoring` again to make that happen.

If you wish to stop monitoring for Trigger events call the `stopMonitoring` method to stop being notified.

```
[[PRXTriggers sharedTriggersManager] stopMonitoring];
```

##### Receiving Trigger Events

Upon receiving a Trigger event (e.g. coming in range of a beacon you are listening for), the callback message you previously defined will be sent and you will be delivered the [PRXTrigger](http://developer.tappoint.com/ios/api-docs/Classes/PRXTrigger.html) object which encapsulates your campaign data.

The [PRXTrigger](http://developer.tappoint.com/ios/api-docs/Classes/PRXTrigger.html) object is available in the userInfo dictionary of the [NSNotification](https://developer.apple.com/library/ios/documentation/Cocoa/Reference/Foundation/Classes/NSNotification_Class/index.html), using the [PRXDetectedTriggerNotificationKeyForTrigger](http://developer.tappoint.com/ios/api-docs/Classes/PRXTriggers.html) key. This includes the unique identifier of the trigger, and the trigger payload data that you defined earlier.

```
- (void)triggerDetected:(NSNotification *)notification
{
    PRXTrigger *trigger = [notification.userInfo objectForKey:PRXDetectedTriggerNotificationKeyForTrigger];

    NSLog(@"Trigger ID: %@", trigger.identifier);
    NSLog(@"Trigger Payload: %@", trigger.payload);
}
```

**NOTE:** iOS does not report that the device has left the range of a beacon until its signal remains undetected for long enough to rule out temporary physical interference with the Bluetooth low-energy radio signal. This can take up to 1 minute.

#### Next Steps

* Prevent the number of times a user receives a notification by [implementing an anti-spam rule](http://developer.tappoint.com/advanced/anti-spam/)
* Add [reporting hooks](http://developer.tappoint.com/advanced/reporting-hooks/) to gain further insights into the effectiveness of a campaign
