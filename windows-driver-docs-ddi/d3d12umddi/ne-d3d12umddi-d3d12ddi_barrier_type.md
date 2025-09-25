## Description

A **D3D12DDI_BARRIER_TYPE** enumeration value indicates the type of resource barrier.

## Constants

### `D3D12DDI_BARRIER_TYPE_GLOBAL`

The barrier is a global barrier. A global barrier applies to all resource memory. Global barriers do not transition texture layouts or force any data decompression.

### `D3D12DDI_BARRIER_TYPE_TEXTURE`

The barrier is a texture barrier. A texture barrier applies to a specific range of texture subresources.

### `D3D12DDI_BARRIER_TYPE_BUFFER`

The barrier is a buffer barrier. A buffer barrier applies to a specific buffer resource.

### `D3D12DDI_BARRIER_TYPE_RANGED`

The buffer is a ranged barrier. A ranged barrier replaces the legacy [**D3D12DDI_RESOURCE_RANGED_BARRIER_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resourcebarrier_0022).

## Remarks

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDIARG_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0088)

[**PFND3D12DDI_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0088)