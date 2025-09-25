# PFND3DKMT_SETGAMMARAMP callback function

## Description

The PFND3DKMT_SETGAMMARAMP callback function sets the gamma ramp.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETGAMMARAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setgammaramp) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETGAMMARAMP Pfnd3dkmtSetgammaramp;

// Definition

NTSTATUS Pfnd3dkmtSetgammaramp
(
	const D3DKMT_SETGAMMARAMP *
)
{...}

```

## Remarks

## See also