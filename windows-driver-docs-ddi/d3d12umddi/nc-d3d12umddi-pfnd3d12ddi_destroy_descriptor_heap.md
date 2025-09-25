# PFND3D12DDI_DESTROY_DESCRIPTOR_HEAP callback function

## Description

Destroys the descriptor heap.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A descriptor heap handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DESTROY_DESCRIPTOR_HEAP Pfnd3d12ddiDestroyDescriptorHeap;

// Definition

VOID Pfnd3d12ddiDestroyDescriptorHeap
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HDESCRIPTORHEAP
)
{...}

PFND3D12DDI_DESTROY_DESCRIPTOR_HEAP

```