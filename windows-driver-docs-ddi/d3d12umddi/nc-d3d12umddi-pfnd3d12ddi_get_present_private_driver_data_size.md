# PFND3D12DDI_GET_PRESENT_PRIVATE_DRIVER_DATA_SIZE callback function

## Description

Gets present private driver data size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_PRESENT_0001 structure.

## Return value

Returns UINT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_PRESENT_PRIVATE_DRIVER_DATA_SIZE Pfnd3d12ddiGetPresentPrivateDriverDataSize;

// Definition

UINT Pfnd3d12ddiGetPresentPrivateDriverDataSize
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_PRESENT_0001 *
)
{...}

PFND3D12DDI_GET_PRESENT_PRIVATE_DRIVER_DATA_SIZE

```

## Remarks

## See also