# _D3DDDI_SURFACEINFO structure

## Description

The D3DDDI_SURFACEINFO structure describes a resource type, such as a surface.

## Members

### `Width` [in]

The width, in pixels, of the surface or volume or the length, in pixels, of the linear resource.

### `Height` [in]

The height, in pixels, of the surface or volume.

### `Depth` [in]

The depth, in pixels, of the volume.

### `pSysMem` [in]

A pointer to a buffer that contains the contents of the resource if the resource exists in system memory and **NULL** if the resource exists in video memory.

Note that this member is valid only if the **Pool** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure for creating the resource is set to the D3DDDIPOOL_SYSTEMMEM value.

### `SysMemPitch` [in]

The pitch, in bytes, of the surface--that is, the distance, in bytes, to the start of the next line.

### `SysMemSlicePitch` [in]

The slice, in bytes, of the volume.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)