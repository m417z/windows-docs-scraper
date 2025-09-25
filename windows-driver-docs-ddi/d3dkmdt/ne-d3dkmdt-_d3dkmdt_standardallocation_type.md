# D3DKMDT_STANDARDALLOCATION_TYPE enumeration

## Description

The **D3DKMDT_STANDARDALLOCATION_TYPE** enumeration contains values that identify particular types of surfaces.

## Constants

### `D3DKMDT_STANDARDALLOCATION_SHAREDPRIMARYSURFACE:1`

Indicates that the surface is a shared primary surface, which is opened by multiple applications that all require direct central processing unit (CPU) access to it.

### `D3DKMDT_STANDARDALLOCATION_SHADOWSURFACE:2`

Indicates that the surface is a shadow surface.

### `D3DKMDT_STANDARDALLOCATION_STAGINGSURFACE:3`

Indicates that the surface is a staging surface.

### `D3DKMDT_STANDARDALLOCATION_GDISURFACE:4`

Indicates that the surface is used for GDI hardware acceleration and Desktop Windows Manager (DWM) redirection.

This constant value is available beginning with Windows 7.

### `D3DKMDT_STANDARDALLOCATION_VGPU:5`

Indicates that the surface is an allocation for a virtual graphics processing unit (GPU). Available starting in WDDM 2.1.

### `D3DKMDT_STANDARDALLOCATION_FENCESTORAGE:6`

Indicates that the surface is an allocation for a fence.

## See also

[**D3DKMDT_SHADOWSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_shadowsurfacedata)

[**D3DKMDT_SHAREDPRIMARYSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_sharedprimarysurfacedata)

[**D3DKMDT_STAGINGSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_stagingsurfacedata)

[**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)