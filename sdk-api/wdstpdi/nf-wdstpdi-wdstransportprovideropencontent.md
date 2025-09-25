# WdsTransportProviderOpenContent function

## Description

Opens a new static view of a content stream.

## Parameters

### `hInstance` [in]

Handle to the instance against which this content will be opened.

### `pwszContentName` [in]

The name of the content stream.

### `phContent` [out]

Pointer to a handle that identifies this content stream to the provider.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This callback is required.

When the handle returned by this function is no longer needed it should be closed with using the [WdsTransportProviderCloseContent](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderclosecontent) callback.