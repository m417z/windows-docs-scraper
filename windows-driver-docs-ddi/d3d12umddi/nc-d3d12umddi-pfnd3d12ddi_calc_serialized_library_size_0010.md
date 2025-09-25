# PFND3D12DDI_CALC_SERIALIZED_LIBRARY_SIZE_0010 callback function

## Description

Calculates serialized library size.

## Parameters

### `hDevice`

A handle to a display device.

### `hLibrary`

A handle to a pipeline library.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_SERIALIZED_LIBRARY_SIZE_0010 Pfnd3d12ddiCalcSerializedLibrarySize0010;

// Definition

SIZE_T Pfnd3d12ddiCalcSerializedLibrarySize0010
(
	D3D12DDI_HDEVICE hDevice
	D3D12DDI_HPIPELINELIBRARY hLibrary
)
{...}

PFND3D12DDI_CALC_SERIALIZED_LIBRARY_SIZE_0010

```