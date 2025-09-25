# WdsTransportServerCompleteRead function

## Description

Provides status of read operation.

## Parameters

### `hProvider` [in]

Handle to the provider. This handle was given to the provider in the [WdsTransportProviderInitialize](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderinitialize) function.

### `ulBytesRead` [in]

The number of bytes read.

### `pvUserData` [in]

User data specified by [WdsTransportProviderReadContent](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderreadcontent).

### `hReadResult` [in]

The status of this read operation.

## Return value

If the function succeeds, the return is **S_OK**.