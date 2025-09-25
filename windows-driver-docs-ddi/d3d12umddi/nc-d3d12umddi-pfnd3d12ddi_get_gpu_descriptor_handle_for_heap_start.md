# PFND3D12DDI_GET_GPU_DESCRIPTOR_HANDLE_FOR_HEAP_START callback function

## Description

Gets the GPU descriptor handle that represents the start of the heap.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A descriptor heap handle.

## Return value

Returns D3D12DDI_GPU_DESCRIPTOR_HANDLE.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_GPU_DESCRIPTOR_HANDLE_FOR_HEAP_START Pfnd3d12ddiGetGpuDescriptorHandleForHeapStart;

// Definition

D3D12DDI_GPU_DESCRIPTOR_HANDLE Pfnd3d12ddiGetGpuDescriptorHandleForHeapStart
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HDESCRIPTORHEAP
)
{...}

PFND3D12DDI_GET_GPU_DESCRIPTOR_HANDLE_FOR_HEAP_START

```

## Remarks

## See also