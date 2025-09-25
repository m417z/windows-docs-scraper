## Description

The **D3D12DDIARG_BARRIER_0094** structure contains the enhanced barrier parameters for the [**PFND3D12DDI_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0094) callback function.

## Members

### `Type`

A [**D3D12DDI_BARRIER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_type) value that identifies the type of enhanced barrier. This member determines which barrier type to use in the union below.

### `GlobalBarrier`

A [**D3D12DDI_GLOBAL_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_global_barrier_0088) structure that describes the global barrier. Use this structure when **Type** is **D3D12DDI_BARRIER_TYPE_GLOBAL**.

### `TextureBarrier`

A [**D3D12DDI_TEXTURE_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_texture_barrier_0088) structure that describes a texture barrier. Use this structure when **Type** is **D3D12DDI_BARRIER_TYPE_TEXTURE**.

### `BufferBarrier`

A [**D3D12DDI_BUFFER_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_buffer_barrier_0088) structure that describes a buffer barrier. Use this structure when **Type** is **D3D12DDI_BARRIER_TYPE_BUFFER**.

### `RangedBarrier`

A [**D3D12DDI_RANGED_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_ranged_barrier_0094) structure that describes a resource ranged barrier. Use this structure when **Type** is **D3D12DDI_BARRIER_TYPE_RANGED**.

## Remarks

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**PFND3D12DDI_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0094)