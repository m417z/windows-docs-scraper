# WSMAN_PLUGIN_RELEASE_SHELL_CONTEXT callback function

## Description

Defines the release shell callback for the plug-in. This function is called to delete the plug-in shell context.

The DLL entry point name must be [WSManPluginReleaseCommandContext](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_release_command_context).

## Parameters

### `shellContext` [in]

Specifies the context that was received when the shell was created.