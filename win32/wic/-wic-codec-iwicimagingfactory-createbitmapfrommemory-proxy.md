# IWICImagingFactory\_CreateBitmapFromMemory\_Proxy function

Proxy function for the [**CreateBitmapFromMemory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createbitmapfrommemory) method.

## Parameters

*pFactory* \[in\]

Type: **[**IWICImagingFactory**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicimagingfactory)\***

*uiWidth* \[in\]

Type: **UINT**

The width of the new bitmap.

*uiHeight* \[in\]

Type: **UINT**

The height of the new bitmap.

*pixelFormat* \[in\]

Type: **REFWICPixelFormatGUID**

The pixel format of the new bitmap.

*cbStride* \[in\]

Type: **UINT**

The [*stride*](https://learn.microsoft.com/windows) of the given pixel data.

*cbBufferSize* \[in\]

Type: **UINT**

The size of *pbBuffer*.

*pbBuffer* \[in\]

Type: **BYTE\***

The buffer used to create the bitmap.

*ppIBitmap* \[out\]

Type: **[**IWICBitmap**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmap)\*\***

A pointer that receives a pointer to the new bitmap.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll;

Wincodec.lib |