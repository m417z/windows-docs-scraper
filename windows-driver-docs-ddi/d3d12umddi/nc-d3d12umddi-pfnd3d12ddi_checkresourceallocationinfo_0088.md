## Description

The **PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0088** callback function supports checking resource allocation information.

## Parameters

### `unnamedParam1`

[in] A handle to the display device (graphics context).

### `unnamedParam2`

[in] Pointer to a [**D3D12DDIARG_CREATERESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0088) structure.

### `unnamedParam3`

A [**D3D12DDI_RESOURCE_OPTIMIZATION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_optimization_flags) value that specifies the resource optimization flags.

### `AlignmentRestriction`

A resource alignment restriction value.

### `VisibleNodeMask`

For a multi-adapter operation, this value indicates the set of nodes where the resource is visible. Passing zero is equivalent to passing one, in order to simplify the usage of single-GPU adapters.

### `unnamedParam6`

Pointer to a [**D3D12DDI_RESOURCE_ALLOCATION_INFO_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resource_allocation_info_0022) structure containing information for resource allocation.

## Remarks

This callback function is part of a two step process of resource creation. This function determines the sizes and alignments of the resource data, additional data header, and additional data is determined, along with the texture layout. When the resource description is passed into this function, the layout of the resource description may be set to _UNDEFINED. This allows the driver to choose any texture layout. When the layout of the resource description is **STANDARD_SWIZZLE** or **ROW_MAJOR**, the driver must return out the corresponding value as its choice.

This callback function is accessed by using the [**D3D12DDI_DEVICE_FUNCS_CORE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0088) structure.

## See also

[**D3D12DDI_DEVICE_FUNCS_CORE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0088)

[**PFND3D12DDI_CREATEHEAPANDRESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createheapandresource_0088)