# WSMAN_PLUGIN_RECEIVE callback function

## Description

Defines the receive callback for a plug-in. This function is called when an inbound request to receive data is received.

The DLL entry point name must be **WSManPluginReceive**.

## Parameters

### `requestDetails`

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags`

Reserved for future use. Must be zero.

### `shellContext`

Specifies the context that was received when the shell was created.

### `commandContext`

If this request is aimed at a command and not a shell, this is the context returned from the **winrm create** operation; otherwise, this parameter is **NULL**.

### `streamSet`

A [WSMAN_STREAM_ID_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_stream_id_set) structure that contains a list of streams for which data is to be received. If this list is empty, all streams that were configured in the shell are implied, which means that all streams are available.

## Remarks

Based on the client request, the **WSMAN_PLUGIN_RECEIVE** callback function can be called against the shell and/or the command. The plug-in calls the [WSManPluginReceiveResult](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginreceiveresult) method for each piece of data that needs to be sent back to the client. After all of the data has been sent, the plug-in calls [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) to end the stream. All parameters passed in are valid until the Windows Remote Management (WinRM) plug-in calls **WSManPluginOperationComplete**.