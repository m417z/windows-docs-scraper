# IWICBitmapFrameDecode::GetColorContexts

## Description

Retrieves the [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) associated with the image frame.

## Parameters

### `cCount` [in]

Type: **UINT**

The number of color contexts to retrieve.

This value must be the size of, or smaller than, the size available to *ppIColorContexts*.

### `ppIColorContexts` [in, out]

Type: **[IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext)****

A pointer that receives a pointer to the [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) objects.

### `pcActualCount` [out]

Type: **UINT***

A pointer that receives the number of color contexts contained in the image frame.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If NULL is passed for *ppIColorContexts*, and 0 is passed for *cCount*, this method will return the total number of color contexts in the image in *pcActualCount*.

The *ppIColorContexts* array must be filled with valid data: each [IWICColorContext*](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) in the array must have been created using [IWICImagingFactory::CreateColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createcolorcontext).