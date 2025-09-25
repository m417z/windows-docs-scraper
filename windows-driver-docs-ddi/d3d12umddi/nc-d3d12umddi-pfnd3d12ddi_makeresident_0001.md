# PFND3D12DDI_MAKERESIDENT_0001 callback function

## Description

pfnMakeResident is used to instruct the OS to add a resource to the device residency list and increment the residency reference count on this allocation.

## Parameters

### `unnamedParam1`

A handle to the display device.

### `unnamedParam2`

A pointer to a [D3D12DDIARG_MAKERESIDENT_0001](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_makeresident_0001) structure that describes the memory pages to make resident.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_MAKERESIDENT_0001 Pfnd3d12ddiMakeresident0001;

// Definition

HRESULT Pfnd3d12ddiMakeresident0001
(
	D3D12DDI_HDEVICE Arg1
	D3D12DDIARG_MAKERESIDENT_0001 *
)
{...}

```