# IWICBitmapLock::GetPixelFormat

## Description

Gets the pixel format of for the locked area of pixels. This can be used to compute the number of bytes-per-pixel in the locked area.

## Parameters

### `pPixelFormat` [out]

Type: **WICPixelFormatGUID***

A pointer that receives the pixel format GUID of the locked area.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.