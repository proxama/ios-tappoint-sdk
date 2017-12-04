//
//  PRXTapPointManager.h
//  TapPointSDK
//
//  Created by Sarah Fuke on 25/07/2017.
//  Copyright © 2017 Proxama Solutions Ltd. All rights reserved.
//

/**
 * A block called by the TapPoint manager when initialisation fails.
 *
 * @param error An NSError describing why initialisation failed.
 */
typedef void (^PRXTapPointFailureBlock)(NSError *error);

/**
 * The PRXTapPointManager protocol is adopted by the shared TapPoint manager.
 */
@protocol PRXTapPointManager <NSObject>

/**
 * Initialises the TapPoint SDK.
 *
 * You should call this method as soon as possible after application launch,
 * or when the network connection first becomes available. You should call this method every time
 * the application launches in the app delegate's didFinishLaunchingWithOptions: method.
 *
 * Initialisation can fail for several reasons, for example the provided application name is invalid, or
 * if the network connection is not functioning. Your application should inspect the NSError object that
 * is returned in the failure block of this method and decide whether it is possible to recover. This might
 * mean listening for when the network connection status changes so that the application can attempt to
 * register again.
 *
 * @param key The application key provided by TapPoint. This is case sensitive.
 * @param failureBlock Block called when initialisation fails. This block contains an NSError
 * argument describing the cause of the error.
 */
- (void)initialiseWithKey:(NSString *)key
						failure:(PRXTapPointFailureBlock)failureBlock
__attribute((nonnull(1)));

@end

/**
 * An object used to retrieve the shared TapPoint manager.
 *
 * The TapPoint manager is able to initialise the TapPoint SDK.
 */
@interface PRXTapPoint : NSObject

/**
 * Returns the shared TapPoint manager.
 *
 * A TapPoint manager is able to initialise the TapPoint SDK.
 *
 * @return The shared TapPoint manager.
 */
+ (id <PRXTapPointManager>)sharedManager;

@end
