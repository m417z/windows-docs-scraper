# PFND3D12DDI_GETMIPPACKING callback function

## Description

Gets MIP packing info.

## Parameters

### `hDevice`

A device handle.

### `hTiledResource`

A tiled resource handle.

### `pNumPackedMips`

Pointer to the number of packed MIPs.

### `pNumTilesForPackedMips`

Pointer to the number of tiles for packed MIPs.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GETMIPPACKING Pfnd3d12ddiGetmippacking;

// Definition

VOID Pfnd3d12ddiGetmippacking
(
	D3D12DDI_HDEVICE hDevice
	D3D12DDI_HRESOURCE hTiledResource
	UINT *pNumPackedMips
	UINT *pNumTilesForPackedMips
)
{...}

PFND3D12DDI_GETMIPPACKING

```

## Remarks

## See also