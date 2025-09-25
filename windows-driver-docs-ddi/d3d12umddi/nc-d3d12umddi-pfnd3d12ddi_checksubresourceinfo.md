# PFND3D12DDI_CHECKSUBRESOURCEINFO callback function

## Description

Check subresource info.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A resource handle.

### `Subresource`

The subresource index.

### `unnamedParam4`

Pointer to a D3D12DDI_SUBRESOURCE_INFO.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKSUBRESOURCEINFO Pfnd3d12ddiChecksubresourceinfo;

// Definition

VOID Pfnd3d12ddiChecksubresourceinfo
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HRESOURCE
	UINT Subresource
	D3D12DDI_SUBRESOURCE_INFO *
)
{...}

PFND3D12DDI_CHECKSUBRESOURCEINFO

```