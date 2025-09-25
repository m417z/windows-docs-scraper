# IWICImagingFactory::CreateBitmapFromHICON

## Description

Creates an [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) from an icon handle.

## Parameters

### `hIcon` [in]

Type: **HICON**

The icon handle to create the new bitmap from.

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.