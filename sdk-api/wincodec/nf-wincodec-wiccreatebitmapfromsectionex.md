# WICCreateBitmapFromSectionEx function

## Description

Returns a [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) that is backed by the pixels of a Windows Graphics Device Interface (GDI) section handle.

## Parameters

### `width` [in]

Type: **UINT**

The width of the bitmap pixels.

### `height` [in]

Type: **UINT**

The height of the bitmap pixels.

### `pixelFormat`

Type: **[REFWICPixelFormatGUID](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats)**

The pixel format of the bitmap.

### `hSection` [in]

Type: **HANDLE**

The section handle. This is a file mapping object handle returned by the [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) function.

### `stride` [in]

Type: **UINT**

The byte count of each scanline.

### `offset` [in]

Type: **UINT**

The offset into the section.

### `desiredAccessLevel` [in]

Type: **[WICSectionAccessLevel](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicsectionaccesslevel)**

The desired access level.

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives the bitmap.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.