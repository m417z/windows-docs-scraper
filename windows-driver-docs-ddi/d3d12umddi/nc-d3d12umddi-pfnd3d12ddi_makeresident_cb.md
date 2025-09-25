# PFND3D12DDI_MAKERESIDENT_CB callback function

## Description

pfnMakeResidentCb is used to instruct the OS to add a resource to the device residency list and increment the residency reference count on this allocation.

## Parameters

### `hRTDevice`

A handle to the display device to be handled in the runtime.

### `hRTPagingQueue`

A handle to the paging queue to be handled in the runtime.

### `unnamedParam3`

Pointer to a [D3DDDI_MAKERESIDENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_makeresident) structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_MAKERESIDENT_CB Pfnd3d12ddiMakeresidentCb;

// Definition

HRESULT Pfnd3d12ddiMakeresidentCb
(
	D3D12DDI_HRTDEVICE hRTDevice
	D3D12DDI_HRTPAGINGQUEUE hRTPagingQueue
	D3DDDI_MAKERESIDENT *
)
{...}

```