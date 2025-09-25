# MFCreateDXSurfaceBuffer function

## Description

Creates a media buffer object that manages a Direct3D 9 surface.

## Parameters

### `riid` [in]

Identifies the type of Direct3D 9 surface. Currently this value must be **IID_IDirect3DSurface9**.

### `punkSurface` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the DirectX surface.

### `fBottomUpWhenLinear` [in]

If **TRUE**, the buffer's [IMF2DBuffer::ContiguousCopyTo](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imf2dbuffer-contiguouscopyto) method copies the buffer into a bottom-up format. The bottom-up format is compatible with GDI for uncompressed RGB images. If this parameter is **FALSE**, the **ContiguousCopyTo** method copies the buffer into a top-down format, which is compatible with DirectX.

For more information about top-down versus bottom-up images, see [Image Stride](https://learn.microsoft.com/windows/desktop/medfound/image-stride).

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the buffer.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

This function creates a media buffer object that holds a pointer to the Direct3D surface specified in *punkSurface*. Locking the buffer gives the caller access to the surface memory. When the buffer object is destroyed, it releases the surface. For more information about media buffers, see [Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers).

**Note** This function does not allocate the Direct3D surface itself.

The buffer object created by this function also exposes the [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface. For more information, see [DirectX Surface Buffer](https://learn.microsoft.com/windows/desktop/medfound/directx-surface-buffer).

This function does not support DXGI surfaces.

## See also

[DirectX Surface Buffer](https://learn.microsoft.com/windows/desktop/medfound/directx-surface-buffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)