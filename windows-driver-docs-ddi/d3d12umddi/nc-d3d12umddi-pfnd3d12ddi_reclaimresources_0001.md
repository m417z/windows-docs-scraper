# PFND3D12DDI_RECLAIMRESOURCES_0001 callback function

## Description

Implemented by the client driver to reclaim resources.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_RECLAIMRESOURCES_0001 structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_RECLAIMRESOURCES_0001 Pfnd3d12ddiReclaimresources0001;

// Definition

HRESULT Pfnd3d12ddiReclaimresources0001
(
	 D3D12DDI_HDEVICE
	D3D12DDIARG_RECLAIMRESOURCES_0001 *
)
{...}

PFND3D12DDI_RECLAIMRESOURCES_0001

```

## Remarks

## See also