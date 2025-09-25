# WSMAN_PLUGIN_SIGNAL callback function

## Description

Defines the signal callback for a plug-in. This function is called when an inbound signal is
received from a client call.

The DLL entry point name for this method must be
**WSManPluginSignal**.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request)
structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags` [in]

Reserved for future use. Must be zero.

### `shellContext` [in]

Specifies the context that was received when the shell was created.

### `commandContext` [in, optional]

If this request is aimed at a command and not a shell, this is the context returned from the
**winrm create** operation; otherwise, this parameter is **NULL**.

### `code` [in]

Specifies the signal that is received from the client. The following codes are common.

#### WSMAN_SIGNAL_SHELL_CODE_TERMINATE

The shell or Command Prompt window was closed. The plug-in should call the
[WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete)
function.

#### WSMAN_SIGNAL_SHELL_CODE_CTRL_C

The signal for CTRL+C was received, and the process was halted. The plug-in should call the
[WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete)
function.

#### WSMAN_SIGNAL_SHELL_CODE_CTRL_BREAK

The signal for CTRL+BREAK was received, and the process was halted. The plug-in should call the
[WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete)
function.

## Remarks

A signal can be received for processing a CTRL+C sequence or one of many other types of custom signals. The
callback is called once for each signal that is received. The plug-in determines which signals cause commands
and/or shells to be shut down. Because signals are shell-specific, the plug-in must initiate the shutdown by
calling the
[WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) method. For
each call, the plug-in should call
**WSManPluginOperationComplete** to
acknowledge receipt and to allow the next signal to be received.