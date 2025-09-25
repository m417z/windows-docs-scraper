# D3D10_DDI_MAP enumeration

## Description

The D3D10_DDI_MAP enumeration type contains values that identify the access levels to map to a subresource in a call to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function.

## Constants

### `D3D10_DDI_MAP_READ`

Read access is requested for the CPU to the subresource.

### `D3D10_DDI_MAP_WRITE`

Write access is requested for the CPU to the subresource.

### `D3D10_DDI_MAP_READWRITE`

Read and write access is requested for the CPU to the subresource.

### `D3D10_DDI_MAP_WRITE_DISCARD`

Write access is requested for the CPU to the subresource. However, the contents of the subresource become undefined during this operation because the requesting application might completely write over the entire region of memory. You can use this access level only with dynamic resources.

### `D3D10_DDI_MAP_WRITE_NOOVERWRITE`

Write access is requested for the CPU to the subresource. However, the requesting application will not overwrite any data that was previously used by the GPU. You can use this access level only with dynamic vertex and index buffers.

## See also

[ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap)