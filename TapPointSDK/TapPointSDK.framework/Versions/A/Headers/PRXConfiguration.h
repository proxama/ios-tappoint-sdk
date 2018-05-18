//
//  PRXConfiguration.h
//  TapPointSDK
//
//  Created by genix on 24/04/2018.
//  Copyright © 2018 Proxama Solutions Ltd. All rights reserved.
//

#import "PRXConsentStatus.h"

#import <Foundation/Foundation.h>

/**
 * A Configuration Manager is able to change consent status of the TapPoint SDK.
 */
@protocol PRXConfigurationManager <NSObject>

/**
 * @param status Status of data consent. You must not set it to undefined status.
 *
 * @throws InvalidArgumentException if given status is equal to undefined.
 */
- (void) setUserDataConsentStatus:(PRXConsentStatus)consentStatus;

/**
 * @return currently stored consent status of the TapPoint SDK
 */
- (PRXConsentStatus) getUserDataConsentStatus;

@end

/**
 * Due to GDPR act, your application has to respect user's permissions related to storing and
 * using his private data (in this case his localisation). This class allows you to change
 * logic of your application depending on current user settings. If user has not defined those
 * permissions we act as if they were given.
 *
 * In order to change user's preferences you have to use ConfigurationManager.
 */
@interface PRXConfiguration : NSObject

/**
 * Get a ConfigurationManager that can be used to change consent status of the TapPoint SDK.
 *
 * @return the instance.
 */
+ (id <PRXConfigurationManager>) sharedConfigurationManager;

@end
