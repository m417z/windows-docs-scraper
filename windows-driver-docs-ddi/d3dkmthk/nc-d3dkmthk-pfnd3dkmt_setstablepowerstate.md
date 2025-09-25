# PFND3DKMT_SETSTABLEPOWERSTATE callback function

## Description

The PFND3DKMT_SETSTABLEPOWERSTATE callback function sets stable power state.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETSTABLEPOWERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setstablepowerstate) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETSTABLEPOWERSTATE Pfnd3dkmtSetstablepowerstate;

// Definition

NTSTATUS Pfnd3dkmtSetstablepowerstate
(
	const D3DKMT_SETSTABLEPOWERSTATE *
)
{...}

```

## Remarks

## See also