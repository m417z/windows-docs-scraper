# WSManPluginReportContext function

## Description

Reports shell and command context back to the Windows Remote Management (WinRM) infrastructure so that further operations can be performed against the shell and/or command. This method is called only for [WSManPluginShell](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_shell) and [WSManPluginCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_command) plug-in entry points.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags` [in]

Reserved for future use. Must be set to zero.

### `context` [in]

Defines the value to pass into all future shell and command operations. Represents either the shell or the command. This value should be unique for all shells, and it should also be unique for all commands associated with a shell.

## Return value

The method returns **NO_ERROR** if it succeeded; otherwise, it returns an error code. If this method returns an error, the plug-in should shut down the current operation and call the [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) method.