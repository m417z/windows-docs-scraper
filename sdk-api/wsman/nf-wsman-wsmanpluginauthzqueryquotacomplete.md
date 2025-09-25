# WSManPluginAuthzQueryQuotaComplete function

## Description

Called from the [WSManPluginAuthzQueryQuota](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_query_quota) plug-in entry point and must be called whether or not the plug-in can carry out the request.

## Parameters

### `senderDetails` [in]

A pointer to the [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that was passed into the [WSManPluginAuthzQueryQuota](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_query_quota) plug-in call.

### `flags` [in]

Reserved for future use. Must be zero.

### `quota` [in, optional]

A pointer to a [WSMAN_AUTHZ_QUOTA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_authz_quota) structure that specifies quota information for a specific user.

### `errorCode` [in]

Reports either a successful or failed authorization. If the authorization is successful, the code should be **ERROR_SUCCESS**. If a failure happens for any other reason, an appropriate error code should be used. Any error from this call will be sent back as a Simple Object Access Protocol (SOAP) fault packet.

### `extendedErrorInformation` [in, optional]

Specifies an XML document that contains any extra error information that needs to be reported to the client. This parameter is ignored if *errorCode* is **NO_ERROR**. The user interface language of the thread should be used for localization.

## Return value

The method returns **ERROR_SUCCESS** if it succeeded; otherwise, it returns **ERROR_INVALID_PARAMETER**. If **ERROR_INVALID_PARAMETER** is returned, either the *senderDetails* parameter was **NULL** or the *flags* parameter was not zero. If the method fails, the default quota is used.

## Remarks

If the *quota* parameter is **null** and the *errorCode* is **NO_ERROR**, the method returns **ERROR_INVALID_PARAMETER** and the plug-in returns the default quota information. If the plug-in is not returning a quota, the authorization plug-in should not specify that quotas are available in the configuration because performance might be affected.