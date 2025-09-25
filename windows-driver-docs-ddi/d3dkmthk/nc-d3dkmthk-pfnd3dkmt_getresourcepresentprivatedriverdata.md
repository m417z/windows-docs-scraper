# PFND3DKMT_GETRESOURCEPRESENTPRIVATEDRIVERDATA callback function

## Description

Pfnd3dkmtGetresourcepresentprivatedriverdata queries the resource private data, which is associated with the resource during Present.

## Parameters

### `unnamedParam1`

Pointer to a [D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_getresourcepresentprivatedriverdata) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETRESOURCEPRESENTPRIVATEDRIVERDATA Pfnd3dkmtGetresourcepresentprivatedriverdata;

// Definition

NTSTATUS Pfnd3dkmtGetresourcepresentprivatedriverdata
(
	D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA *
)
{...}

```

## Remarks

## See also