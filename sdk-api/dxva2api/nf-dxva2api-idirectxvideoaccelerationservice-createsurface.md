# IDirectXVideoAccelerationService::CreateSurface

## Description

Creates a DirectX Video Acceleration (DXVA) video processor or DXVA decoder render target.

## Parameters

### `Width` [in]

The width of the surface, in pixels.

### `Height` [in]

The height of the surface, in pixels.

### `BackBuffers` [in]

The number of back buffers. The method creates *BackBuffers* + 1 surfaces.

### `Format` [in]

The pixel format, specified as a **D3DFORMAT** value or FOURCC code. For more information, see the Direct3D documentation.

### `Pool` [in]

The memory pool in which to create the surface, specified as a **D3DPOOL** value. For more information, see the Direct3D documentation. Decoders should generally use the value D3DPOOL_DEFAULT.

### `Usage` [in]

Reserved. Set this value to zero.

### `DxvaType` [in]

The type of surface to create. Use one of the following values.

| Value | Meaning |
| --- | --- |
| **DXVA2_VideoDecoderRenderTarget** | Video decoder render target. |
| **DXVA2_VideoProcessorRenderTarget** | Video processor render target. Used for [IDirectXVideoProcessor::VideoProcessBlt](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-videoprocessblt) operations. |
| **DXVA2_VideoSoftwareRenderTarget** | Software render target. This surface type is for use with software DXVA devices. |

### `ppSurface` [out]

The address of an array of **IDirect3DSurface9** pointers allocated by the caller. The size of the array must be 1 + *BackBuffers* (enough for the back buffers plus one front buffer). The method fills the array with **IDirect3DSurface9** pointers. The caller must release all of the interface pointers. In addition, the front buffer holds a reference count on each of the back buffers. Therefore, the back buffers are never deleted until the front buffer is deleted.

### `pSharedHandle` [in, out]

A pointer to a handle that is used to share the surfaces between Direct3D devices. Set this parameter to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **D3DERR_INVALIDCALL** | Invalid parameter |
| **E_FAIL** | The DirectX Video Acceleration Manager is not initialized. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

If the method returns **E_FAIL**, try calling [IDirect3DDeviceManager9::ResetDevice](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirect3ddevicemanager9-resetdevice) to reset the DirectX Video Acceleration Manager.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoAccelerationService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoaccelerationservice)