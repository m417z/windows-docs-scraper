# WdsTransportProviderGetContentSize function

## Description

Retrieves the size of an open content stream.

## Parameters

### `hContent` [in]

Handle to an open content stream, opened with the [WdsTransportProviderOpenContent](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportprovideropencontent) callback.

### `pContentSize` [out]

Pointer to a large integer that receives the size of the content stream.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.