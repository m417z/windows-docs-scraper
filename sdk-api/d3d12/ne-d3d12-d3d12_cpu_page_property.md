# D3D12_CPU_PAGE_PROPERTY enumeration

## Description

Specifies the CPU-page properties for the heap.

## Constants

### `D3D12_CPU_PAGE_PROPERTY_UNKNOWN:0`

The CPU-page property is unknown.

### `D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE:1`

The CPU cannot access the heap, therefore no page properties are available.

### `D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE:2`

The CPU-page property is write-combined.

### `D3D12_CPU_PAGE_PROPERTY_WRITE_BACK:3`

The CPU-page property is write-back.

## Remarks

This enum is used by the [D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)