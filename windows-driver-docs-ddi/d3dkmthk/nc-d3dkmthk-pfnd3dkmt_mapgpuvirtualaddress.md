# PFND3DKMT_MAPGPUVIRTUALADDRESS callback function

## Description

Pfnd3dkmtMapgpuvirtualaddress maps a graphics processing unit (GPU) virtual address ranges to a specific allocation range or puts it to the Invalid or Zero state.

## Parameters

### `unnamedParam1`

Pointer to a [D3DDDI_MAPGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_MAPGPUVIRTUALADDRESS Pfnd3dkmtMapgpuvirtualaddress;

// Definition

NTSTATUS Pfnd3dkmtMapgpuvirtualaddress
(
	D3DDDI_MAPGPUVIRTUALADDRESS *
)
{...}

```

## Remarks

## See also