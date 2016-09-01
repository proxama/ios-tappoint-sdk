//
//  PRXErrorCode.h
//  TapPointSDK
//
//  Created by Dominic Heale on 03/12/2014.
//  Copyright (c) 2014 Proxama Solutions Ltd. All rights reserved.
//

/**
 * Errors reported from the TapPoint SDK are divided into public and internal errors.
 * Public errors are recoverable errors caused either by a temporary condition in the app's environment,
 * i.e. no internet condition, or because of invalid data being passed to one of the SDK APIs.
 *
 * Internal errors are non-recoverable by the application and should be reported to Proxama support.
 *
 * If an API call to TapPoint results in a non-200 HTTP status code then this will be reported as the error code,
 * as a result error codes between 100 and 599 are reserved.
 */
typedef NS_ENUM(NSInteger, PRXErrorCode) {
	/** An API call failed because of no internet connection. */
	PRXErrorCodeNoInternet = 1,
	/** An application name passed into an API is unrecognised by TapPoint. */
	PRXErrorCodeUnknownAppName = 2,
	/** An attempt has been made to use the SDK on a platform not configured on TapPoint. */
	PRXErrorCodeUnknownVariant = 3,
	/** A call to an API has been made without the application being authenticated. */
	PRXErrorCodeNotAuthenticated = 4,
	/** An attempt to authenticate using a different app name has been made when the application was already authenticated with a previous app name. */
	PRXErrorCodeAlreadyAuthenticated = 5,
	/** An attempt to authenticate has been made while a previous attempt is still in progress. */
	PRXErrorCodeAuthenticationAlreadyInProgress = 6,
	/** An attempt to create storage internally within the SDK has failed. Internal error. */
	PRXErrorCodeStorageCreationError = 7,
	/** An attempt to connect to storage internally within the SDK has failed. Internal error. */
	PRXErrorCodeStorageConnectionError = 8,
	/** An attempt to write to storage internally within the SDK has failed. Internal error. */
	PRXErrorCodeStorageWriteError = 9,
	/** An attempt to read from storage internally within the SDK has failed. Internal error. */
	PRXErrorCodeStorageReadError = 10,
	/** The server has returned an invalid response to a request made by the SDK. Internal error. */
	PRXErrorCodeInvalidServerResponse = 11,
	/** An attempt to synchronise has been made while a previous attempt is still in progress. */
	PRXErrorCodeSynchronizationAlreadyInProgress = 12,
	/** A network request timed out before a response was received. */
	PRXErrorCodeNetworkTimeout = 13,
};