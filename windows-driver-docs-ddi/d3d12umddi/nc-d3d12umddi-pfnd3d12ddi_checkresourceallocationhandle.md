# PFND3D12DDI_CHECKRESOURCEALLOCATIONHANDLE callback function

## Description

Checks resource allocation handle.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A resource handle.

## Return value

Returns D3DKMT_HANDLE.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKRESOURCEALLOCATIONHANDLE Pfnd3d12ddiCheckresourceallocationhandle;

// Definition

D3DKMT_HANDLE Pfnd3d12ddiCheckresourceallocationhandle
(
	 D3D12DDI_HDEVICE
	 D3D10DDI_HRESOURCE
)
{...}

PFND3D12DDI_CHECKRESOURCEALLOCATIONHANDLE

```