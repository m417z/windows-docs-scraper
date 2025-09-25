# IWICImagingFactory::CreateBitmapFromMemory

## Description

Creates an [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) from a memory block.

## Parameters

### `uiWidth` [in]

Type: **UINT**

The width of the new bitmap.

### `uiHeight` [in]

Type: **UINT**

The height of the new bitmap.

### `pixelFormat` [in]

Type: **REFWICPixelFormatGUID**

The pixel format of the new bitmap. For valid pixel formats, see [Native Pixel Formats](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats).

### `cbStride` [in]

Type: **UINT**

The number of bytes between successive scanlines in *pbBuffer*.

### `cbBufferSize` [in]

Type: **UINT**

The size of *pbBuffer*.

### `pbBuffer` [in]

Type: **BYTE***

The buffer used to create the bitmap.

### `ppIBitmap` [out]

Type: **[IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap)****

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The size of the [IWICBitmap](https://learn.microsoft.com/windows/desktop/wic/-wic-imp-iwicbitmapdecoder) to be created must be smaller than or equal to the size of the image in *pbBuffer*.

The stride of the destination bitmap will equal the *stride* of the source data, regardless of the width and height specified.

The *pixelFormat* parameter defines the pixel format for both the input data and the output bitmap.