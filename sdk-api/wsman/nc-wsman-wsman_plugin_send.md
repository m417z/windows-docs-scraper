# WSMAN_PLUGIN_SEND callback function

## Description

Defines the send callback for a plug-in. This function is called for each object that is received from a client. Each object received causes the callback to be called once.
After the data is processed, the Windows Remote Management (WinRM) plug-in calls [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) to acknowledge receipt and to allow the next object to be delivered.

The DLL entry point name must be **WSManPluginSend**.

## Parameters

### `requestDetails`

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags`

If this is the last object for the stream, this parameter is set to **WSMAN_FLAG_NO_MORE_DATA**.
Otherwise, it is set to zero.

### `shellContext`

Specifies the context that was received when the shell was created.

### `commandContext`

If this request is aimed at a command and not a shell, this is the context returned from the **winrm create** operation; otherwise, this parameter is **NULL**.

### `stream`

Specifies the stream that is associated with the inbound object.

### `inboundData`

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that contains data being sent to the specified stream. It is in the form of binary data.