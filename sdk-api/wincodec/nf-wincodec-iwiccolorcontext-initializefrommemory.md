# IWICColorContext::InitializeFromMemory

## Description

Initializes the color context from a memory block.

## Parameters

### `pbBuffer` [in]

Type: **const BYTE***

The buffer used to initialize the [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext).

### `cbBufferSize` [in]

Type: **UINT**

The size of the *pbBuffer* buffer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Once a color context has been initialized, it can't be re-initialized.