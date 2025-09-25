# MFCreateWICBitmapBuffer function

## Description

Creates a media buffer object that manages a Windows Imaging Component (WIC) bitmap.

## Parameters

### `riid` [in]

Set this parameter to `__uuidof(IWICBitmap)`.

### `punkSurface` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the bitmap surface. The bitmap surface must be a WIC bitmap that exposes the [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) interface.

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)