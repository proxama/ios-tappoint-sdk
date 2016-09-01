//
//  PRXTriggerEventType.h
//  TapPointSDK
//
//  Created by Craig Walker on 06/01/2015.
//  Copyright (c) 2015 Proxama Solutions Ltd. All rights reserved.
//

/**
 * A PRXTriggerEventType represents the type of event that has occurred when the monitoring for
 * triggers produces an event.
 */
typedef NS_ENUM(NSInteger, PRXTriggerEventType) {
	/**
	 * Indicates the user has been notified of the occurrence of a trigger. This might
	 * be in the form of a notification, or some alternative UI element.
	 */
	PRXTriggerEventTypeUserNotified = 1,

	/**
	 * When the user has already been notified about the occurrence of a trigger,
	 * the user then wishes to find out more information.
	 */
	PRXTriggerEventTypeUserSelected = 2,

	/**
	 * When the user has already been notified about the occurrence of a trigger and has "clicked-through",
	 * the user has taken an action that is significant to the application such as making a purchase.
	 */
	PRXTriggerEventTypeUserConverted = 3
};
