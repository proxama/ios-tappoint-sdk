//
//  PRXTrigger.h
//  TapPointSDK
//
//  Created by Craig Walker on 09/12/2014.
//  Copyright (c) 2014 Proxama Solutions Ltd. All rights reserved.
//

#import "PRXTriggerRateStatistics.h"

/**
 * A PRXTrigger object corresponds to a trigger definition on TapPoint.
 * The object contains the custom payload data for the triggerable event
 * (as defined on TapPoint) that the application previously synced down to the device.
 */
@interface PRXTrigger : NSObject <NSCoding>

/**
 * The unique identifier of the trigger on TapPoint.
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/**
 * A key/value representation of the trigger's custom payload data that is defined on TapPoint.
 */
@property (nonatomic, copy, readonly) NSDictionary *payload;

/**
 * An optional property containing the rate at which trigger event notifications have been delivered to
 * the application.
 *
 * In the case where rate statistics are not provided for this trigger, nil will be returned.
 */
@property (nonatomic, copy, readonly) PRXTriggerRateStatistics *rateStatistics;

@end
