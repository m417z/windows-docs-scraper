# WSManPluginFreeRequestDetails function

## Description

Releases memory that is allocated for the [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure, which is passed into operation plug-in entry points. This method is optional and can be called at any point after a plug-in entry point is called and before the entry point calls the [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) method. After this method is called, the memory will be released and the plug-in will be unable to access any of the parameters in the [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.