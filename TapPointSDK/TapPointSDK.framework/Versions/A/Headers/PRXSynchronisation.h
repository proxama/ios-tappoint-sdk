//
//  PRXSynchronisation.h
//  TapPointSDK
//
//  Created by Craig Walker on 16/12/2014.
//  Copyright (c) 2014 Proxama Solutions Ltd. All rights reserved.
//

#import "PRXSyncResult.h"

/**
 * A block called by the synchronisation manager when synchronisation succeeds.
 *
 * @param synchronisationResult The result of a successful synchronisation with TapPoint which holds
 * information about triggers that have been added and removed.
 */
typedef void (^PRXSynchronisationSuccessBlock)(PRXSyncResult *synchronisationResult);

/**
 * A block called by the synchronisation manager when synchronisation fails.
 *
 * @param error An NSError describing why synchronisation failed.
 */
typedef void (^PRXSynchronisationFailureBlock)(NSError *error);

/**
 * The PRXSynchronisationManager protocol is adopted by the shared synchronisation manager.
 */
@protocol PRXSynchronisationManager <NSObject>

/**
 * Synchronises the local cache with the data stored on TapPoint. This should be called after 
 * application authentication.
 *
 * Synchronisation can fail for several reasons, for example if the network connection is not functioning.
 * Your application should inspect the NSError object that is returned in the failure block of this method
 * and decide whether it is possible to recover. This might mean listening for when the network connection 
 * status changes so that the application can attempt to synchronise again.
 *
 * @param successBlock Block called when synchronisation succeeds. You should use this
 * block to perform additional steps that depend on successful synchronisation.
 *
 * @param failureBlock Block called when synchronisation fails. This block contains an NSError
 * argument describing the cause of the error.
 */
- (void)synchroniseWithSuccess:(PRXSynchronisationSuccessBlock)successBlock failure:(PRXSynchronisationFailureBlock)failureBlock;

@end

/**
 * An object used to retrieve the shared synchronisation manager.
 *
 * A synchronisation manager is able to synchronise with TapPoint.
 */
@interface PRXSynchronisation : NSObject

/**
 * Returns the shared synchronisation manager.
 *
 * The shared synchronisation manager is used to synchronise with TapPoint in order to ensure 
 * that the local cache is up-to-date with the data stored on TapPoint.
 *
 * @return The shared synchronisation manager.
 */
+ (id <PRXSynchronisationManager>)sharedSynchronisationManager;

@end


