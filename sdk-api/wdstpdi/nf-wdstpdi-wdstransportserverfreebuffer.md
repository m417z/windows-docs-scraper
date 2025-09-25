# WdsTransportServerFreeBuffer function

## Description

Releases memory used by a buffer.

## Parameters

### `hProvider` [in]

Handle to the provider. This handle was given to the provider in the [WdsTransportProviderInitialize](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderinitialize) function.

### `pvBuffer` [in]

Pointer to location of buffer to be released.

## Return value

If the function succeeds, the return is **S_OK**.