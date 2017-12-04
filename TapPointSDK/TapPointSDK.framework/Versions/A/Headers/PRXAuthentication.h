//
//  PRXAuthentication.h
//  TapPointSDK
//
//  Created by Michael Murphy on 03/12/2014.
//  Copyright (c) 2014 Proxama Solutions Ltd. All rights reserved.
//

/**
 * A block called by the authentication manager when authentication succeeds.
 */
typedef void (^PRXAuthenticateSuccessBlock)();

/**
 * A block called by the authentication manager when authentication fails.
 *
 * @param error An NSError describing why authentication failed.
 */
typedef void (^PRXAuthenticateFailureBlock)(NSError *error);

/**
 * The PRXAuthenticationManager protocol is adopted by the shared authentication manager.
 */
@protocol PRXAuthenticationManager <NSObject>

/**
 * Authenticates an application with TapPoint.
 *
 * You must wait for this method to call its success block before attempting to use any TapPoint 
 * features. You should call this method as soon as possible after application launch,
 * or when the network connection first becomes available. You should call this method every time 
 * the application launches in the app delegate's didFinishLaunchingWithOptions: method, even if 
 * the application has been successfully authenticated on a previous launch.
 *
 * Authentication can fail for several reasons, for example the provided application name is invalid, or 
 * if the network connection is not functioning. Your application should inspect the NSError object that
 * is returned in the failure block of this method and decide whether it is possible to recover. This might 
 * mean listening for when the network connection status changes so that the application can attempt to 
 * register again.
 *
 * @param appName Name of the application on TapPoint. This can be found in your app's settings
 * on TapPoint's campaign portal. This is case sensitive.
 * @param successBlock Block called when authentication succeeds. You should use this
 * block to perform additional steps that depend on successful authentication, such as
 * synchronising with TapPoint.
 * @param failureBlock Block called when authentication fails. This block contains an NSError
 * argument describing the cause of the error.
 */
- (void)authenticateWithAppName:(NSString *)appName
						success:(PRXAuthenticateSuccessBlock)successBlock
						failure:(PRXAuthenticateFailureBlock)failureBlock
						__attribute((nonnull(1)));

@end

/**
 * An object used to retrieve the shared authentication manager.
 *
 * An authentication manager is able to authenticate an application with TapPoint.
 */
@interface PRXAuthentication : NSObject

/**
 * Returns the shared authentication manager.
 *
 * An authentication manager is able to authenticate an application with TapPoint. In a typical
 * application, you should use the shared instance of the authentication manager to
 * authenticate with TapPoint using the method `authenticateWithAppName:success:failure`.
 *
 * @return The shared authentication manager.
 */
+ (id <PRXAuthenticationManager>)sharedAuthenticationManager;

@end
