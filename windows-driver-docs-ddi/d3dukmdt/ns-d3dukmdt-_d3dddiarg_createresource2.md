# _D3DDDIARG_CREATERESOURCE2 structure

## Description

Contains information for creating a resource. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `Format` [in]

A value of type [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) that indicates the format of the resources.

### `Pool` [in]

A value of type [D3DDDI_POOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_pool) that indicates the type of memory pool that the resources are created from.

### `MultisampleType` [in]

A value of type [D3DDDIMULTISAMPLE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddimultisample_type) that indicates the number of samples for a multiple-sampled surface. If the surface is not multiple sampled, this value is D3DDDIMULTISAMPLE_NONE (0).

### `MultisampleQuality` [in]

The quality level of rendering samples in a multiple-sampled surface. The quality level must be a number from 0 through 7 that represents a quality level from 1 through 8, respectively.

Note that even if the surface is not multiple-sampled (that is, if **D3DDDIMULTISAMPLE_NONE** is specified in **MultisampleType**) it can still have a quality level that is greater than 1 (which is specified by using a number greater than 0).

### `pSurfList` [in]

An array of [D3DDDI_SURFACEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_surfaceinfo) structures for the list of surfaces (or other resource types) to create.

### `SurfCount` [in]

The number of resources in the array that is specified by the **pSurfList** member.

### `MipLevels` [in]

The number of MIP-map levels for the resources.

### `Fvf` [in]

The FVF format for vertex buffers.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the primary surface is created on (if the resource contains a primary surface).

### `RefreshRate` [in]

A [D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational) structure that specifies the refresh rate that the resource is used with. This member is applicable only if the resource is the primary surface and the **MatchGdiPrimary** bit-field flag is not set in the **Flags** member. In addition, if the **InterlacedRefresh** bit-field flag is set in **Flags**, the user-mode display driver determines that the refresh rate is interleaved (otherwise, progressive).

### `hResource` [in/out]

A handle to the resource. On input to the [CreateResource2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource2) function, **hResource** specifies the handle that the driver should use anytime it calls back into the Microsoft Direct3D runtime.

The driver generates a unique handle and passes it back to the Direct3D runtime. On output from the [CreateResource2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource2) function, **hResource** specifies the handle that the Direct3D runtime should use in subsequent driver calls to identify the resource.

### `Flags` [in]

A [D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags) structure that identifies the type of resources to create. Note that some of the bit-field flags in **D3DDDI_RESOURCEFLAGS** require that additional bit-field flags are set as well.

### `Rotation` [in]

A [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)-typed value that identifies the orientation of the resource.

For example, consider that the user-mode display driver receives a request for a 480x640 surface to be rotated 90 degrees (**D3DDDI_ROTATION_90**). The driver should allocate the surface in 640x480 mode for scanning purposes. When rendering to the surface, the driver should perform the 90 degree rotation.

Orientations other than **D3DDDI_ROTATION_IDENTITY** are set only when the **Primary** bit-field flag is also set in the **Flags** member.

### `Flags2` [in]

A [D3DDDI_RESOURCEFLAGS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags2) structure that identifies the type of resources to create. Note that some of the bit-field flags in **D3DDDI_RESOURCEFLAGS2** require that additional bit-field flags are set as well.

## See also

[CreateResource2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource2)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDIMULTISAMPLE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddimultisample_type)

[D3DDDI_POOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_pool)

[D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational)

[D3DDDI_RESOURCEFLAGS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags2)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[D3DDDI_SURFACEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_surfaceinfo)