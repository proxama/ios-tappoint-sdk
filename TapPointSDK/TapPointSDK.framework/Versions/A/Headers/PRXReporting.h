//
//  PRXReporting.h
//  TapPointSDK
//
//  Created by Craig Walker on 06/01/2015.
//  Copyright (c) 2015 Proxama Solutions Ltd. All rights reserved.
//

#import "PRXTrigger.h"
#import "PRXTriggerEventType.h"

/**
 * The PRXReportingManager protocol is adopted by the shared reporting manager.
 */
@protocol PRXReportingManager <NSObject>

/**
 * Reports a trigger event for a given trigger based on the provided event type.
 *
 * An event could potentially fail to be reported on, this could be down
 * to the application not currently being authenticated with TapPoint. 
 * This would be output in the log. If this is the case, you should authenticate with
 * TapPoint using the shared authentication manager found in the PRXAuthentication class.
 *
 * @param eventType The type of event to report on.
 * @param triggerID The unique ID of the PRXTrigger that the event is related to.
 */
- (void)reportTriggerEvent:(PRXTriggerEventType)eventType
				 triggerID:(NSString *)triggerID;

/**
 * Reports a trigger event for a given trigger based on the provided event type.
 *
 * An event could potentially fail to be reported on, this could be down
 * to the application not currently being authenticated with TapPoint.
 * This would be output in the log. If this is the case, you should authenticate with
 * TapPoint using the shared authentication manager found in the PRXAuthentication class.
 *
 * @param eventType The type of event to report on.
 * @param triggerID The unique ID of the PRXTrigger that the event is related to.
 * @param extEventRef A user defined external event reference to be attached to the event.
 */
- (void)reportTriggerEvent:(PRXTriggerEventType)eventType
				 triggerID:(NSString *)triggerID
	externalEventReference:(NSString *)extEventRef;

/**
 * Reports a user event with the provided name and properies.
 *
 * An event could potentially fail to be reported on, this could be down
 * to the application not currently being authenticated with TapPoint.
 * This would be output in the log. If this is the case, you should authenticate with
 * TapPoint using the shared authentication manager found in the PRXAuthentication class.
 *
 * @param eventName The name of the event to report.
 * @param customProperties A user defined set of properties to be attached to the event.
 */
- (void)reportUserEvent:(NSString *)eventName
		 customProperties:(NSDictionary *)customProperties;

/**
 * Ensures all subsequent reporting events will be associated with a unique user reference.
 *
 * @param extUserRef The external user reference to associate with all reporting events. By providing nil or empty,
 * you are indicating that any existing user reference will be cleared and all subsequent reporting events will not be
 * associated with a user.
 */
- (void)setExternalUserReference:(NSString *)extUserRef;

@end

/**
 * An object used to retrieve the shared reporting manager.
 *
 * A reporting manager is used to allow events involving data or services managed by TapPoint to be reported
 * on for analytics purposes.
 */
@interface PRXReporting : NSObject

/**
 * Returns the shared reporting manager.
 *
 * A reporting manager is used to allow events involving data or services managed by TapPoint to be reported
 * on for analytics purposes.
 *
 * @return The shared reporting manager.
 */
+ (id <PRXReportingManager>)sharedReportingManager;

@end
