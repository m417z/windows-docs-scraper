# ID2D1DeviceContext::CreateBitmapFromWicBitmap(IWICBitmapSource,ID2D1Bitmap1)

## Description

Creates an [ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap) by copying the specified Microsoft Windows Imaging Component (WIC) bitmap.

## Parameters

### `wicBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The WIC bitmap to copy.

### `bitmap` [out]

Type: **[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)****

When this method returns, contains a pointer to a pointer to the new bitmap. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)