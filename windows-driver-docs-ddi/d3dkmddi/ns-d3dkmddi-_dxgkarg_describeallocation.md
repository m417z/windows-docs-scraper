# _DXGKARG_DESCRIBEALLOCATION structure

## Description

The DXGKARG_DESCRIBEALLOCATION structure describes an existing allocation.

## Members

### `hAllocation` [in]

A handle to an allocation that information is requested for. The driver previously returned this handle in the **hAllocation** member of the [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure from a call to the driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function.

### `Width` [out]

The width of the allocation, in pixels. The driver returns the width value.

### `Height` [out]

The height of the allocation, in pixels. The driver returns the height value.

### `Format` [out]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the allocation. The driver returns the format value.

### `MultisampleMethod` [out]

A [D3DDDI_MULTISAMPLINGMETHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_multisamplingmethod) structure that describes the multiple-sampling method that is used for the allocation. The driver returns the description.

### `RefreshRate` [out]

A [D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational) structure that indicates the refresh rate that the primary surface was created with, if applicable.

### `PrivateDriverFormatAttribute` [out]

A UINT value that specifies a private format attribute for the allocation. The driver specifies surface format attributes (for example, the pixel layout of a tiled surface) that it otherwise cannot expose to the operating system.

The operating system uses the information in **PrivateDriverFormatAttribute** to compare two surfaces. For example, an A8R8B8G8 800x600 surface and an X8R8B8G8 800x600 surface should have the same information in **PrivateDriverFormatAttribute** if they have the same format attributes, which includes pixel layout.

### `Flags` [out]

This member is reserved.

Supported starting with Windows 8.

### `Rotation` [out]

This member is reserved.

Supported starting with Windows 8.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_MULTISAMPLINGMETHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_multisamplingmethod)

[D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_DESCRIBEALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_describeallocationflags)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiDescribeAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_describeallocation)