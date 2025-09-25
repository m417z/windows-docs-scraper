# WSMAN_PLUGIN_AUTHORIZE_RELEASE_CONTEXT callback function

## Description

Releases the context that a plug-in reports from either [WSManPluginAuthzUserComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzusercomplete) or [WSManPluginAuthzOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzoperationcomplete). For a particular user, the context reported for both calls is allowed to be the same, as long as the plug-in infrastructure handles the scenario appropriately. This method is synchronous, and there are no callbacks that are called as a result.

This method will be called under the following scenarios:

* After the operation is complete, the [WSManPluginAuthzOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzoperationcomplete) context is released. For some operations, such as get, the context will be released after the response is sent for the get operation. For more complex operations, such as enumeration, the context will not be released until the enumeration has completed.
* When the user record times out due to inactivity, the [WSManPluginAuthzUser](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_authorize_user) method will be called again the next time a request comes in for that user.
* If re-authorization needs to occur, the old context will be released after the new one is acquired. The old context will always be released regardless of whether the authorization succeeds.

The DLL entry point name for this method must be **WSManPluginAuthzReleaseContext**.

## Parameters

### `userAuthorizationContext` [in]

Specifies the context that was returned by either [WSManPluginAuthzUserComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzusercomplete) or [WSManPluginAuthzOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzoperationcomplete). If these methods return no context, this method will not be called.