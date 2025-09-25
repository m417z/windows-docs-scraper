# WDS_TRANSPORTPROVIDER_INIT_PARAMS structure

## Description

This structure is used by the [WdsTransportProviderInitialize](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderinitialize) callback function.

## Members

### `ulLength`

The length of this structure.

### `ulMcServerVersion`

The multicast server's version.

### `hRegistryKey`

An open handle to the registry key where this provider should
store and retrieve its settings.

### `hProvider`

A handle that the provider can use to uniquely identify itself in calls to the multicast server.