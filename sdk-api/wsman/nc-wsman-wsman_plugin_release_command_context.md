# WSMAN_PLUGIN_RELEASE_COMMAND_CONTEXT callback function

## Description

Defines the release command callback for the plug-in. This function is called to delete the plug-in command context.

The DLL entry point name must be **WSManPluginReleaseCommandContext**.

## Parameters

### `shellContext` [in]

Specifies the context that was received when the shell was created.

### `commandContext` [in]

If this request is aimed at a command and not a shell, this is the context returned from the **winrm create** operation; otherwise, this parameter is **NULL**.