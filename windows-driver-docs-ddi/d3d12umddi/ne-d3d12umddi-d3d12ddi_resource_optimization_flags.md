# D3D12DDI_RESOURCE_OPTIMIZATION_FLAGS enumeration

## Description

The **D3D12DDI_RESOURCE_OPTIMIZATION_FLAGS** enumeration is a bitwise OR value that defines a resource's optimization flags.

## Constants

### `D3D12DDI_RESOURCE_OPTIMIZATION_FLAG_NONE:0x0`

No options are specified.

### `D3D12DDI_RESOURCE_OPTIMIZATION_FLAG_SHADER_RESOURCE:0x1`

Perform shader resource optimizations.

### `D3D12DDI_RESOURCE_OPTIMIZATION_FLAG_UNORDERED_ACCESS:0x2`

Perform unordered access view optimizations.

### `D3D12DDI_RESOURCE_OPTIMIZATION_FLAG_PRIMARY:0x4`

Perform primary heap optimizations.

### `D3D12DDI_RESOURCE_OPTIMIZATION_FLAG_DETERMINISTIC:0x8`

Perform deterministic optimizations.

## See also

[**D3D12_RESOURCE_FLAGS**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags)

[**PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_checkresourceallocationinfo_0088)