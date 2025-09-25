# WdsTransportProviderGetContentMetadata function

## Description

Retrieves metadata for an open content stream.

## Parameters

### `hContent` [in]

Handle to an open content stream, opened with the [WdsTransportProviderOpenContent](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportprovideropencontent) callback.

### `pvData` [out]

Pointer to the location in memory to receive content metadata.

### `pulLength` [out]

The size of the buffer located at *pvData* in bytes.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.