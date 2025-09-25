# PFND3D12DDI_GET_CPU_DESCRIPTOR_HANDLE_FOR_HEAP_START callback function

## Description

Gets the CPU descriptor handle that represents the start of the heap.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A user mode driver handle type.

## Return value

Returns D3D12DDI_CPU_DESCRIPTOR_HANDLE that represents the start of the heap.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_CPU_DESCRIPTOR_HANDLE_FOR_HEAP_START Pfnd3d12ddiGetCpuDescriptorHandleForHeapStart;

// Definition

D3D12DDI_CPU_DESCRIPTOR_HANDLE Pfnd3d12ddiGetCpuDescriptorHandleForHeapStart
(
	 D3D12DDI_HDEVICE hDevice
	 D3D12DDI_HDESCRIPTORHEAP
)
{...}

PFND3D12DDI_GET_CPU_DESCRIPTOR_HANDLE_FOR_HEAP_START

```

## See also