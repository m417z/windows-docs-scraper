# WSMAN_PLUGIN_CONNECT callback function

## Description

Defines the connect callback for a plug-in.

The DLL entry point name must be
**WSManPluginConnect**.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request)
structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags` [in]

Reserved for future use. Must be set to zero.

### `shellContext` [in]

Specifies the context returned from creating the shell for which this connection request needs to be
associated.

### `commandContext` [in, optional]

If this request is aimed at a command and not a shell, this is the context returned from the
**winrm create** operation; otherwise, this parameter is **NULL**.

### `inboundConnectInformation` [in, optional]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that specifies an
optional inbound object that contains extra data for the connection.