# PFND3D12DDI_CHECKRESOURCEALLOCATIONINFO_0022 callback function

## Description

The *pfnCheckResourceAllocationInfo* callback function supports checking resource allocation information.

## Parameters

### `unnamedParam1`

*hDevice*

A handle to the display device (graphics context).

### `unnamedParam2`

*CreateResource* [in]

A pointer to a create resource.

### `unnamedParam3`

*ResourceOptimizationFlags*

Resource optimization flags.

### `AlignmentRestriction`

An alignment restriction value.

### `VisibleNodeMask`

A visible node mask.

### `unnamedParam6`

*pInfo* [out]

Information for resource allocation.

## Remarks

This callback function is part of a two step process of resource creation. This function determines the sizes and alignments of the resource data, additional data header, and additional data is determined, along with the texture layout. When the resource description is passed into this function, the layout of the resource description may be set to _UNDEFINED. This allows the driver to choose any texture layout. When the layout of the resource description is **STANDARD_SWIZZLE** or **ROW_MAJOR**, the driver must return out the corresponding value as its choice.

This callback function is accessed by using the [D3D12DDI_DEVICE_FUNCS_CORE_0010](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0010) structure.