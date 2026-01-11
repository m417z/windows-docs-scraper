# MFCreateDXGISurfaceBuffer function

## Description

Creates a media buffer to manage a Microsoft DirectX Graphics Infrastructure (DXGI) surface.

## Parameters

### `riid` [in]

Identifies the type of DXGI surface. This value must be **IID_ID3D11Texture2D** or **IID_ID3D12Resource**.

### `punkSurface` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the DXGI surface.

### `uSubresourceIndex` [in]

The zero-based index of a subresource of the surface. The media buffer object is associated with this subresource.

### `fBottomUpWhenLinear` [in]

If **TRUE**, the buffer's [IMF2DBuffer::ContiguousCopyTo](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-contiguouscopyto) method copies the buffer into a bottom-up format. The bottom-up format is compatible with GDI for uncompressed RGB images. If this parameter is **FALSE**, the **ContiguousCopyTo** method copies the buffer into a top-down format, which is compatible with Direct3D.

For more information about top-down versus bottom-up images, see [Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride).

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the buffer.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned buffer object supports the following interfaces:

* [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)
* [IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2)
* [IMFDXGIBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgibuffer)
* [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer)

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)