# IDXVAHD_Device::CreateVideoSurface

## Description

Creates one or more Microsoft Direct3D video surfaces.

## Parameters

### `Width` [in]

The width of each surface, in pixels.

### `Height` [in]

The height of each surface, in pixels.

### `Format` [in]

The pixel format, specified as a **D3DFORMAT** value or FOURCC code. For more information, see [Video FOURCCs](https://learn.microsoft.com/windows/desktop/medfound/video-fourccs).

### `Pool` [in]

The memory pool in which the surface is created. This parameter must equal the **InputPool** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. Call the [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) method to get this value.

### `Usage` [in]

Reserved. Set to 0.

### `Type` [in]

The type of surface to create, specified as a member of the [DXVAHD_SURFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_surface_type) enumeration.

### `NumSurfaces` [in]

The number of surfaces to create.

### `ppSurfaces` [out]

A pointer to an array of **IDirect3DSurface9** pointers. The *NumSurfaces* parameter specifies the number of elements in the array. The method fills the array with pointers to the new video surfaces. The caller must release the pointers.

### `pSharedHandle` [in, out]

Reserved. Set to **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device)