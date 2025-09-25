# WSMAN_PLUGIN_COMMAND callback function

## Description

Defines the command callback for a plug-in. This function is called when a request for a command is received. All Windows Remote Management plug-ins that support shell operations and need to create commands must implement this callback.

The DLL entry point name must be **WSManPluginCommand**.

## Parameters

### `requestDetails`

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags`

Reserved for future use. Must be set to zero.

### `shellContext`

Specifies the context returned from creating the shell for which this command needs to be associated.

### `commandLine`

Specifies the command line to be run.

### `arguments`

A pointer to a [WSMAN_COMMAND_ARG_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_command_arg_set) structure that specifies the command-line arguments to be passed to the command.

## Remarks

The WinRM (WinRM) plug-in will call the [WSManPluginReportContext](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginreportcontext) method to register a command context for the command. All operations on this command are passed into this context. The context must be valid until the [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) method is called by the plug-in to indicate that either the command is complete or the shell was shut down. All parameters passed in are valid until the WinRM plug-in calls **WSManPluginOperationComplete**.