# WSManPluginAuthzOperationComplete function

## Description

Called from the [WSManPluginAuthzOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_operation) plug-in entry point. It reports either a successful or failed authorization for a user operation.

## Parameters

### `senderDetails` [in]

A pointer to the [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that was passed into the [WSManPluginAuthzOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_operation) plug-in call.

### `flags` [in]

Reserved for future use. Must be zero.

### `userAuthorizationContext` [in, optional]

Specifies a plug-in defined context that is used to help track user context information. This context can be returned to multiple calls, to this call, or to an operation call. The plug-in manages reference counting for all calls. If the user record times out or re-authorization is required, the WinRM (WinRM) infrastructure calls [WSManPluginAuthzReleaseContext](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_release_context).

### `errorCode` [in]

Reports either a successful or failed authorization. If the authorization is successful, the code should be **ERROR_SUCCESS**. If the user is not authorized to perform the operation, the error should be **ERROR_ACCESS_DENIED**. If a failure happens for any other reason, an appropriate error code should be used. Any error from this call will be sent back as a Simple Object Access Protocol (SOAP) fault packet.

### `extendedErrorInformation` [in, optional]

Specifies an XML document that contains any extra error information that needs to be reported to the client. This parameter is ignored if *errorCode* is **NO_ERROR**. The user interface language of the thread should be used for localization.

## Return value

The method returns **ERROR_SUCCESS** if it succeeded; otherwise, it returns **ERROR_INVALID_PARAMETER**. If **ERROR_INVALID_PARAMETER** is returned, either the *senderDetails* parameter was **NULL** or the *flags* parameter was not zero.