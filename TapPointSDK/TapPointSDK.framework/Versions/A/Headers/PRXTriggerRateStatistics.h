//
//  PRXTriggerRateStatistics.h
//  TapPointSDK
//
//  Created by Craig Walker on 23/03/2015.
//  Copyright (c) 2015 Proxama Solutions Ltd. All rights reserved.
//

/**
 * An object that holds statistical information about the occurrence of trigger events. This should
 * be used to identify whether your application provides an appropriate number of trigger events to
 * the user over periods of time.
 */
@interface PRXTriggerRateStatistics : NSObject <NSCoding>

/**
 * The last time an event involving a trigger in this group was sent to the application.
 */
@property (nonatomic, copy, readonly) NSDate *lastEventTimestamp;

/**
 * The number of events sent to the application involving a trigger in this group in the last 60 minutes.
 */
@property (nonatomic, readonly) NSInteger eventsInTheLastHour;

/**
 * The number of events sent to the application involving a trigger in this group in the last 24 hours.
 */
@property (nonatomic, readonly) NSInteger eventsInTheLastDay;

/**
 * The number of events sent to the application involving a trigger in this group in the last 7 days.
 */
@property (nonatomic, readonly) NSInteger eventsInTheLastWeek;

@end
