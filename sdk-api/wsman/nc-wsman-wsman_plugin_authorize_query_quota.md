# WSMAN_PLUGIN_AUTHORIZE_QUERY_QUOTA callback function

## Description

Retrieves quota information for the user after a connection has been authorized. This method will be called only if the configuration specifies that quotas are enabled within the authorization plug-in.

The DLL entry point name for this method must be **WSManPluginAuthzQueryQuota**.

## Parameters

### `pluginContext` [in]

Specifies the context that was returned by a call to [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup). This parameter represents a specific application initialization of a WinRM plug-in.

### `senderDetails` [in]

A pointer to the [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that specifies the identification information of the user.

### `flags` [in]

Reserved for future use. Must be zero.

## Remarks

The quota is queried on the first call by a particular user and will not be requeried until after the user record times out due to an idle time-out of activity or until a system-wide configuration period is exceeded.

The plug-in must call the [WSManPluginAuthzQueryQuotaComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzqueryquotacomplete) function to terminate the operation whether or not the plug-in can carry out the request. If successful, the plug-in should give a set of quota information that is relevant for this particular user. If the plug-in fails to process the request for any reason, an appropriate error should be recorded through the callback method and the error will get propagated back to the client as a Simple Object Access Protocol (SOAP) fault if possible; otherwise, the error will be an empty HTTP 500 status error.