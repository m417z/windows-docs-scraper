# PFND3D12DDI_CHECKEXISITINGRESOURCEALLOCATIONINFO_0022 callback function

## Description

The [pfnCheckExistingResourceAllocationInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_checkexisitingresourceallocationinfo_0022) callback function supports checking existing resource allocation information.

## Parameters

### `unnamedParam1`

*hDevice*

A handle to the display device (graphics context).

### `unnamedParam2`

hResource

A resource handle.

### `unnamedParam3`

pInfo [out]

Information for resource allocation.

## Remarks

This callback function is part of a two step process of resource creation. After the [pfnCheckResourceAllocationInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_checkresourceallocationinfo_0022) callback function, the resource is created. During resource creation, the layout is never _UNDEFINED, since the driver will have returned a resolved texture layout.

## See also

[pfnCheckResourceAllocationInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_checkresourceallocationinfo_0022)