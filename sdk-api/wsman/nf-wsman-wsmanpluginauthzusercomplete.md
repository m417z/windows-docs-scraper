# WSManPluginAuthzUserComplete function

## Description

Called from the [WSManPluginAuthzUser](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_user) plug-in entry point and reports either a successful or failed user connection authorization.

## Parameters

### `senderDetails` [in]

A pointer to the [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that was passed into the [WSManPluginAuthzUser](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_user) plug-in call.

### `flags` [in]

Reserved for future use. Must be set to zero.

### `userAuthorizationContext` [in, optional]

Specifies a plug-in defined context that is used to help track user context information. This context can be returned to multiple calls, to this call, or to an operation call. The plug-in manages reference counting for all calls. If the user record times out or re-authorization is required, the WinRM infrastructure calls [WSManPluginAuthzReleaseContext](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_release_context).

### `impersonationToken` [in, optional]

Specifies the identity of the user. This parameter is the *clientToken* that was passed into *senderDetails*. If the plug-in changes the user context, a new impersonation token should be returned.

**Note** This token is released after the operation has been completed.

### `userIsAdministrator` [in]

Set to **TRUE** if the user is an administrator. Otherwise, this parameter is **FALSE**.

### `errorCode` [in]

Reports either a successful or failed authorization. If the authorization is successful, the code should be **ERROR_SUCCESS**. If the user is not authorized to perform the operation, the error should be **ERROR_ACCESS_DENIED**. If a failure happens for any other reason, an appropriate error code should be used. Any error from this call will be sent back as a SOAP fault packet.

### `extendedErrorInformation` [in, optional]

Specifies an XML document that contains any extra error information that needs to be reported to the client. This parameter is ignored if *errorCode* is **NO_ERROR**. The user interface language of the thread should be used for localization.

## Return value

The method returns **ERROR_SUCCESS** if it succeeded; otherwise, it returns **ERROR_INVALID_PARAMETER**. If **ERROR_INVALID_PARAMETER** is returned, either the *senderDetails* parameter was **NULL** or the *flags* parameter was not zero.

## Remarks

If the impersonation token passed into *senderDetails* is not the identity with which the operation should be performed, or if no impersonation token is available and the plug-in specifies a new identity to carry out the request, the plug-in should return the new *impersonationToken* that the WSMan infrastructure will use to impersonate the client before calling into the operation plug-in. If an impersonation token is provided in the *senderDetails* and the plug-in wants to carry out the operation under that identity, the plug-in should copy the impersonation token from the *senderDetails* into the *impersonationToken* parameter. If the plug-in wants to carry out the request under the context of the Internet Information Services (IIS) host process, the *impersonationToken* should be **NULL**. If the *impersonationToken* is **NULL**, the thread will impersonate the process token before calling into the operation plug-in.

If the *userIsAdministrator* parameter is set to **TRUE**, the user is allowed to view and delete shells owned by different users.