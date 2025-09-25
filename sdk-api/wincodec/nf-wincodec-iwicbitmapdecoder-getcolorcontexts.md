# IWICBitmapDecoder::GetColorContexts

## Description

Retrieves the [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) objects of the image.

## Parameters

### `cCount` [in]

Type: **UINT**

The number of color contexts to retrieve.

This value must be the size of, or smaller than, the size available to *ppIColorContexts*.

### `ppIColorContexts` [in, out]

Type: **[IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext)****

A pointer that receives a pointer to the [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext).

### `pcActualCount` [out]

Type: **UINT***

A pointer that receives the number of color contexts contained in the image.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.