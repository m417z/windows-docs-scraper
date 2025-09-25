# PFND3DKMT_FLUSHHEAPTRANSITIONS callback function

## Description

The Pfnd3dkmtFlushheaptransitions callback function flushes heap transitions.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_FLUSHHEAPTRANSITIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flushheaptransitions) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_FLUSHHEAPTRANSITIONS Pfnd3dkmtFlushheaptransitions;

// Definition

NTSTATUS Pfnd3dkmtFlushheaptransitions
(
	D3DKMT_FLUSHHEAPTRANSITIONS *
)
{...}

```

## Remarks

## See also