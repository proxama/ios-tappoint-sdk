//
//  PRXTriggers.h
//  TapPointSDK
//
//  Created by Craig Walker on 09/12/2014.
//  Copyright (c) 2014 Proxama Solutions Ltd. All rights reserved.
//

/**
 * Name of the notification posted when a trigger is detected.
 *
 * If you want to respond to trigger events in your application, register as an 
 * observer for this notification. The `userInfo` dictionary of the posted notification
 * contains the key PRXDetectedTriggerNotificationKeyForTrigger whose value is a
 * PRXTrigger object containing information about the trigger that was detected.
 */
extern NSString * const PRXTriggersDetectedNotification;

/**
 * The key in the `userInfo` dictionary of notifications posted when a trigger is detected
 * whose value is a PRXTrigger object containing information about the trigger.
 */
extern NSString * const PRXDetectedTriggerNotificationKeyForTrigger;

/**
 * The PRXTriggersManager protocol is adopted by the shared triggers manager.
 *
 * ## Responding to trigger detections in the background
 *
 * When a trigger is detected while your application is closed, iOS will launch your application
 * in the background to give it an opportunity to respond to the trigger. To do this, ensure that 
 * startMonitoring is called before the end of application:didfinishlaunchingWithOptions: so that
 * a notification can be posted, and respond appropriately to the notification.
 *
 * Ideally, your application should check why it was launched in the background
 * by examining the options passed to -application:didFinishLaunchingWithOptions: and look for the
 * UIApplicationLaunchOptionsLocationKey, which means that the application was launched
 * in response to a location event.
 */
@protocol PRXTriggersManager <NSObject>

/**
 * Starts monitoring for triggers.
 *
 * This method does not guarantee that triggers will actually be detected, as this depends
 * on many external factors depending on the type of trigger, including:
 *
 * - the application already being authenticated,
 * - the device having required hardware (e.g. BLE),
 * - services being enabled on the handset (e.g. Bluetooth), and
 * - location services being authorized by the user.
 *
 * It is your responsibility to ensure that these conditions are met. You should prompt the user to
 * authorise the use of location services and provide a value for the key
 * `NSLocationAlwaysUsageDescription` in your application's info plist. The value of this key
 * appears in the permission dialog, and should explain to the user why the app needs access
 * to their location. Ideally, applications should provide some information in advance about
 * why the application requires the user's location.
 *
 * If monitoring becomes interrupted (for example, bluetooth is turned off temporarily) then
 * as long as this method has been called at some point in the lifetime of the application,
 * monitoring will be resumed.
 */
- (void)startMonitoring;

/**
 * Stops monitoring for triggers.
 *
 * This method stops the application from monitoring for triggers, and no more notifications
 * will be posted about trigger events.
 */
- (void)stopMonitoring;

@end

/**
 * An object used to retrieve the shared triggers manager.
 *
 * A triggers manager is able to control when the application monitors for triggers.
 */
@interface PRXTriggers : NSObject

/**
 * Returns the shared triggers manager.
 *
 * A triggers manager is able to control scanning for triggers using the startScanning and
 * stopScanning methods. When triggers are detected, the manager posts a notification
 * with the name given by PRXTriggersDetectedNotification whose user info contains information
 * about the trigger.
 *
 * @return The shared triggers manager.
 */
+ (id <PRXTriggersManager>)sharedTriggersManager;

@end
