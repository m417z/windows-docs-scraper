# PFND3D12DDI_RESOURCEBARRIER_0022 callback function

## Description

The *pfnResourceBarrier* callback function supports resource barriers.

## Parameters

### `unnamedParam1`

**hDrvCommandList**

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `Count`

Specifies a count.

### `unnamedParam3`

**ResourceBarrier** [in]

A pointer to a resource barrier as a [D3D12DDIARG_RESOURCE_BARRIER_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_resource_barrier_0022) structure.

## Remarks

Access this callback function by using a command list functions structure, such as the **D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_0020** structure.

## See also

[D3D12DDIARG_RESOURCE_BARRIER_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_resource_barrier_0022)