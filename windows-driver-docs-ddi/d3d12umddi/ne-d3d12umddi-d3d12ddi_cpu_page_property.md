## Description

A **D3D12DDI_CPU_PAGE_PROPERTY** value specifies the CPU page properties for a heap.

## Constants

### `D3D12DDI_CPU_PAGE_PROPERTY_NOT_AVAILABLE:0`

The CPU cannot access the heap; therefore no page properties are available.

### `D3D12DDI_CPU_PAGE_PROPERTY_WRITE_COMBINE:1`

The CPU page property is write-combined.

### `D3D12DDI_CPU_PAGE_PROPERTY_WRITE_BACK:2`

The CPU page property is write-back.

## See also

[**D3D12DDIARG_CREATEHEAP_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createheap_0001)