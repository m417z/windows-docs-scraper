# PFND3DKMT_SETDISPLAYMODE callback function

## Description

The PFND3DKMT_SETDISPLAYMODE callback function sets the allocation that is used to scan out to the display.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETDISPLAYMODE Pfnd3dkmtSetdisplaymode;

// Definition

NTSTATUS Pfnd3dkmtSetdisplaymode
(
	const D3DKMT_SETDISPLAYMODE *
)
{...}

```

## Remarks

## See also