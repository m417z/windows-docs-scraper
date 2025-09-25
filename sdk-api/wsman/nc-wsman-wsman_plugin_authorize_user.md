# WSMAN_PLUGIN_AUTHORIZE_USER callback function

## Description

Authorizes a connection. The plug-in should verify that this user is allowed to perform any operations. If the user is allowed to perform operations, the plug-in must report a success. If the user is not allowed to carry out any type of operation, a failure must be returned.

Every new connection does not need to be authorized. After a user has been authorized to connect, a user record is created to track the activities of the user. While that record exists, all new connections will automatically be authorized. The user record will time-out after a configurable amount of time after no activity is detected.

The DLL entry point name for this method must be **WSManPluginAuthzUser**.

## Parameters

### `pluginContext` [in]

Specifies the context that was returned by a call to [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup). This parameter represents a specific application initialization of a WinRM plug-in.

### `senderDetails` [in]

A pointer to the [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that specifies the identification information of the user to be authorized.

### `flags` [in]

Reserved for future use. Must be set to zero.

## Remarks

The plug-in must call [WSManPluginAuthzUserComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzusercomplete) to report either that the user was successfully authorized with **NO_ERROR** or that the user was not authorized with **ERROR_ACCESS_DENIED**. An **ERROR_WSMAN_REDIRECT_REQUIRED** error should be reported if an HTTP redirect is required for this user, and the new HTTP URI should be recorded in *extendedErrorInformation* of the **WSManPluginAuthzUserComplete** method. All other errors report a failure to the client, but no specific information is reported.