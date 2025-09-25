# D3D12DDI_HEAP_FLAGS enumeration

## Description

The **D3D12DDI_HEAP_FLAGS** enumeration specifies Direct3D 12 heap options.

## Constants

### `D3D12DDI_HEAP_FLAG_NONE:0x0`

No flags.

### `D3D12DDI_HEAP_FLAG_NON_RT_DS_TEXTURES:0x2`

The heap supports resources allocated for other than Render Target (RT) and Depth-Stencil (DS) textures.

### `D3D12DDI_HEAP_FLAG_BUFFERS:0x4`

The heap supports resources allocated for buffers.

### `D3D12DDI_HEAP_FLAG_COHERENT_SYSTEMWIDE:0x8`

The heap supports resources allocated for coherent system wide.

### `D3D12DDI_HEAP_FLAG_PRIMARY:0x10`

The heap supports resources allocated for primary.

### `D3D12DDI_HEAP_FLAG_RT_DS_TEXTURES:0x20`

The heap supports resources allocated for RT and DS textures.

### `D3D12DDI_HEAP_FLAG_0041_DENY_L0_DEMOTION:0x40`

Supports transparent demotion to system memory by restricting the supported memory segments for the heap.

## See also

[**D3D12DDIARG_CREATEHEAP_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createheap_0001)