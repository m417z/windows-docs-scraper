# PFND3D12DDI_GET_DESCRIPTOR_SIZE_IN_BYTES callback function

## Description

The PFND3D12DDI_GET_DESCRIPTOR_SIZE_IN_BYTES callback function gets the size of the handle, in bytes, for a given type of descriptor heap.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

The D3D12DDI_DESCRIPTOR_HEAP_TYPE-typed value that specifies the type of descriptor heap to get the size of the handle increment for.

## Return value

Returns UINT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_DESCRIPTOR_SIZE_IN_BYTES Pfnd3d12ddiGetDescriptorSizeInBytes;

// Definition

UINT Pfnd3d12ddiGetDescriptorSizeInBytes
(
	 D3D12DDI_HDEVICE hDevice
	 D3D12DDI_DESCRIPTOR_HEAP_TYPE
)
{...}

PFND3D12DDI_GET_DESCRIPTOR_SIZE_IN_BYTES

```

## See also