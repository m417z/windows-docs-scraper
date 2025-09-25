# WdsTransportProviderReadContent function

## Description

Reads content from an open content stream.

## Parameters

### `hContent` [in]

Handle to an open content stream to be read. This is the handle return by the [WdsTransportProviderOpenContent](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportprovideropencontent) callback.

### `pBuffer` [in]

Pointer to location to receive read content.

### `ulBytesToRead` [in]

The size in bytes of the buffer at the location specified by the *pBuffer* parameter.

### `pContentOffset` [in]

The offset into the content stream specified by *hContent* from which to start reading.

### `pvUserData` [in]

User specified data passed to the callback function.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.