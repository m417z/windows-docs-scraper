# PFND3D12DDI_COPY_DESCRIPTORS_SIMPLE_0003 callback function

## Description

Copies a descriptor.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `NumDescriptors`

The number of descriptors to copy.

### `DestDescriptorRangeStart`

A handle to the descriptor range in the destination.

### `SrcDescriptorRangeStart`

A handle to the descriptor range in the source.

### `DescriptorHeapsType`

The descriptor heap type.

## Prototype

```cpp
//Declaration

PFND3D12DDI_COPY_DESCRIPTORS_SIMPLE_0003 Pfnd3d12ddiCopyDescriptorsSimple0003;

// Definition

VOID Pfnd3d12ddiCopyDescriptorsSimple0003
(
	 D3D12DDI_HDEVICE
	UINT NumDescriptors
	D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart
	D3D12DDI_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart
	D3D12DDI_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType
)
{...}

PFND3D12DDI_COPY_DESCRIPTORS_SIMPLE_0003

```