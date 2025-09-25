# PFND3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT callback function

## Description

The PFND3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT callback function changes the private-format attribute of a video present source.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplayprivatedriverformat) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT Pfnd3dkmtSetdisplayprivatedriverformat;

// Definition

NTSTATUS Pfnd3dkmtSetdisplayprivatedriverformat
(
	const D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT *
)
{...}

```

## Remarks

## See also