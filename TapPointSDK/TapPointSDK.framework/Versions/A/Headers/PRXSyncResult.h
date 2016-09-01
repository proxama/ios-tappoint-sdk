//
//  PRXSyncResult.h
//  TapPointSDK
//
//  Created by Craig Walker on 16/12/2014.
//  Copyright (c) 2014 Proxama Solutions Ltd. All rights reserved.
//

/**
 * An object that provides information after a synchronisation with TapPoint has taken place.
 *
 * This includes information about what triggers have been added and removed.
 */
@interface PRXSyncResult : NSObject

/**
 * A NSArray of PRXTrigger objects that have been added after a synchronisation has occurred.
 *
 * This will be an empty NSArray if no triggers have been added after synchronisation with TapPoint.
 */
@property (nonatomic, copy, readonly) NSArray *triggersAdded;

/**
 * A NSArray of PRXTrigger objects that have been removed after a synchronisation has occurred.
 *
 * This will be an empty NSArray if no triggers have been removed after synchronisation with TapPoint.
 */
@property (nonatomic, copy, readonly) NSArray *triggersRemoved;

@end
