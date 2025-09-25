# WdsTransportProviderCreateInstance function

## Description

Opens a new instance of a content provider.

## Parameters

### `pwszConfigString` [in]

Configuration information for this instance of the content provider.

### `phInstance` [out]

Receives a pointer to a handle that identifies this instance. When the instance is no longer needed, the handle should be closed with the [WdsTransportProviderCloseInstance](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportprovidercloseinstance) callback.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.