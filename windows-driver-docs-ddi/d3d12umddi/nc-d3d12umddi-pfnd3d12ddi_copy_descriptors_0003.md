# PFND3D12DDI_COPY_DESCRIPTORS_0003 callback function

## Description

Copy descriptors.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `NumDestDescriptorRanges`

The number of descriptor ranges in the destination.

### `pDestDescriptorRangeStarts`

Pointer to the start of the descriptor range in the destination.

### `pDestDescriptorRangeSizes`

Pointer to the descriptor range sizes in the destination.

### `NumSrcDescriptorRanges`

The number of descriptor ranges in the source.

### `pSrcDescriptorRangeStarts`

Pointer to the start of the descriptor range in the source.

### `pSrcDescriptorRangeSizes`

Pointer to the descriptor range sizes in the destination.

### `DescriptorHeapsType`

The descriptor heap type.

## Prototype

```cpp
//Declaration

PFND3D12DDI_COPY_DESCRIPTORS_0003 Pfnd3d12ddiCopyDescriptors0003;

// Definition

VOID Pfnd3d12ddiCopyDescriptors0003
(
	 D3D12DDI_HDEVICE
	UINT NumDestDescriptorRanges
	CONST D3D12DDI_CPU_DESCRIPTOR_HANDLE *pDestDescriptorRangeStarts
	CONST UINT *pDestDescriptorRangeSizes
	UINT NumSrcDescriptorRanges
	CONST D3D12DDI_CPU_DESCRIPTOR_HANDLE *pSrcDescriptorRangeStarts
	CONST UINT *pSrcDescriptorRangeSizes
	D3D12DDI_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType
)
{...}

PFND3D12DDI_COPY_DESCRIPTORS_0003

```