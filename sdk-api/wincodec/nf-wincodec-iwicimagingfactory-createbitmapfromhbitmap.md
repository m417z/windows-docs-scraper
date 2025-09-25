# IWICImagingFactory::CreateBitmapFromHBITMAP

## Description

Creates an [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) from a bitmap handle.

## Parameters

### `hBitmap` [in]

Type: **HBITMAP**

A bitmap handle to create the bitmap from.

### `hPalette` [in]

Type: **HPALETTE**

A palette handle used to create the bitmap.

### `options` [in]

Type: **[WICBitmapAlphaChannelOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapalphachanneloption)**

The alpha channel options to create the bitmap.

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a non-palletized bitmap, set NULL for the *hPalette* parameter.

## See also

[GDI+ Bitmap class](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[GDI+ Bitmap.GetHBITMAP method](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethbitmap)

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[WICBitmapAlphaChannelOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapalphachanneloption)