# D3D12DDIARG_RESOURCE_BARRIER_0022 structure

## Description

The **D3D12DDIARG_RESOURCE_BARRIER_0022** structure contains the resource barrier parameters for the [**PFND3D12DDI_RESOURCEBARRIER_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resourcebarrier_0022).

## Members

### `Type`

The type of resource barrier as a [**D3D12DDI_RESOURCE_BARRIER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_barrier_type) value. This member determines which barrier type to use in the union below.

### `Flags`

A barrier flag as a [**D3D12DDI_RESOURCE_BARRIER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_barrier_flags) value.

### `Transition`

A [**D3D12DDI_RESOURCE_TRANSITION_BARRIER_0003**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resource_transition_barrier_0003) structure that describes the transition of subresources between different usages. This structure's members specify the before and after usages of the subresources.

### `Ranged`

A [**D3D12DDI_RESOURCE_RANGED_BARRIER_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resource_ranged_barrier_0022) structure that describes a ranged barrier.

### `UAV`

A [**D3D12DDI_RESOURCE_UAV_BARRIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resource_uav_barrier) structure that describes a resource in which all UAV accesses (reads or writes) must complete before any future UAV accesses (read or write) can begin.

## See also

[**PFND3D12DDI_RESOURCEBARRIER_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resourcebarrier_0022)