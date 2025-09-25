# WSManPluginOperationComplete function

## Description

Reports the completion of an operation by all operation entry points except for the [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup) and [WSManPluginShutdown](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_shutdown) methods.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags` [in]

Reserved for future use. Must be zero.

### `errorCode` [in]

Reports any failure in the operation. If this parameter is not **NO_ERROR**, any result data that has not been sent will be discarded and the error will be sent.

### `extendedInformation` [in, optional]

Specifies an XML document that contains any extra error information that needs to be reported to the client. This parameter is ignored if *errorCode* is **NO_ERROR**. The user interface language of the thread should be used for localization.

## Return value

The method returns **NO_ERROR** if it succeeded; otherwise, it returns an error code. If the operation is unsuccessful, the plug-in must stop the current operation and clean up any data associated with this operation. The *requestDetails* structure is not valid if an error is received and must not be passed to any other WinRM (WinRM) method.

## Remarks

The **WSManPluginOperationComplete** function is used to report the completion of the
data stream for [WSManPluginReceive](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_receive). The [WSManPluginShell](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_shell) and [WSManPluginCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_command) operations must also call this function when the shell and command operations are complete.