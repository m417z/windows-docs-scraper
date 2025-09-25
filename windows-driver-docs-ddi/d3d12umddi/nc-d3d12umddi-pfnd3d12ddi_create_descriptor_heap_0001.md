# PFND3D12DDI_CREATE_DESCRIPTOR_HEAP_0001 callback function

## Description

Create descriptor heap.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_DESCRIPTOR_HEAP_0001 structure.

### `unnamedParam3`

A descriptor heap handle.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_DESCRIPTOR_HEAP_0001 Pfnd3d12ddiCreateDescriptorHeap0001;

// Definition

HRESULT Pfnd3d12ddiCreateDescriptorHeap0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_DESCRIPTOR_HEAP_0001 *
	 D3D12DDI_HDESCRIPTORHEAP
)
{...}

PFND3D12DDI_CREATE_DESCRIPTOR_HEAP_0001

```