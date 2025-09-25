# WdsTransportProviderInitialize function

## Description

Initializes a content provider.

## Parameters

### `pInParameters` [in]

A pointer to a [WDS_TRANSPORTPROVIDER_INIT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wdstpdi/ns-wdstpdi-wds_transportprovider_init_params) structure that informs the content provider about the server.

### `pSettings` [out]

A pointer to a [WDS_TRANSPORTPROVIDER_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wdstpdi/ns-wdstpdi-wds_transportprovider_settings) structure that informs the server about the content provider.

### `ulLength` [in]

The size in bytes of the buffer at the location specified by the *pSettings* parameter.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.