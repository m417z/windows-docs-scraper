# WSMAN_PLUGIN_SHELL callback function

## Description

Defines the shell callback for a plug-in. This function is called when a request for a new shell is received. All Windows Remote Management plug-ins that support shell operations need to implement this callback.

The DLL entry point name must be **WSManPluginShell**.

## Parameters

### `pluginContext`

Specifies the context that was returned by a call to the [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup) method. This parameter represents a specific application initialization of a WinRM plug-in.

### `requestDetails`

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags`

Reserved for future use. Must be set to zero.

### `startupInfo`

A pointer to a [WSMAN_SHELL_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_startup_info_v10) structure that contains startup information for the shell.

### `inboundShellInformation`

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that specifies an optional inbound object that contains extra data for the shell.

## Remarks

The WinRM (WinRM) plug-in calls [WSManPluginReportContext](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginreportcontext) to register a shell context for the shell. All operations on this shell pass into this context. If the shell has shut down or the plug-in checks the *requestDetails* parameter and reports that the operation was canceled, the plug-in should call [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete). All parameters passed in are valid until the WinRM plug-in calls **WSManPluginOperationComplete**.