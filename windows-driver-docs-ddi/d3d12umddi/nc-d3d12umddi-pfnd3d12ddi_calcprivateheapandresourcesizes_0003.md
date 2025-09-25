# PFND3D12DDI_CALCPRIVATEHEAPANDRESOURCESIZES_0003 callback function

## Description

**PFND3D12DDI_CALCPRIVATEHEAPANDRESOURCESIZES_0003** calculates the number of bytes required for a private heap and resource.

## Parameters

### `unnamedParam1`

[in] A handle to the display device (graphics context).

### `unnamedParam2`

[in/optional] Pointer to a [**D3D12DDIARG_CREATEHEAP_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createheap_0001) structure that describes the heap.

### `unnamedParam3`

Pointer to a **D3D12DDIARG_CREATERESOURCE_0003** structure that describes the resource.

## Return value

Returns a [**D3D12DDI_HEAP_AND_RESOURCE_SIZES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_heap_and_resource_sizes) structure that specifies the sizes of the heap and resource, in bytes.