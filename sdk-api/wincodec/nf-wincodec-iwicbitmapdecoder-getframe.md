# IWICBitmapDecoder::GetFrame

## Description

Retrieves the specified frame of the image.

## Parameters

### `index` [in]

Type: **UINT**

The particular frame to retrieve.

### `ppIBitmapFrame` [out]

Type: **[IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode)****

A pointer that receives a pointer to the [IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.