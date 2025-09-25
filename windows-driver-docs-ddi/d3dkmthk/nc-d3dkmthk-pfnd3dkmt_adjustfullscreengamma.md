# PFND3DKMT_ADJUSTFULLSCREENGAMMA callback function

## Description

The PFND3DKMT_ADJUSTFULLSCREENGAMMA callback function adjusts to full screen gamma.

## Parameters

### `unnamedParam1` [in]

Pointer to a [D3DKMT_ADJUSTFULLSCREENGAMMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adjustfullscreengamma) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_ADJUSTFULLSCREENGAMMA Pfnd3dkmtAdjustfullscreengamma;

// Definition

NTSTATUS Pfnd3dkmtAdjustfullscreengamma
(
	D3DKMT_ADJUSTFULLSCREENGAMMA *
)
{...}

```