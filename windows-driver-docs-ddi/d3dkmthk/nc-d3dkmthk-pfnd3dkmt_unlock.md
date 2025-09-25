# PFND3DKMT_UNLOCK callback function

## Description

The PFND3DKMT_UNLOCK callback function unlocks a list of allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unlock) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UNLOCK Pfnd3dkmtUnlock;

// Definition

NTSTATUS Pfnd3dkmtUnlock
(
	const D3DKMT_UNLOCK *
)
{...}

```

## Remarks

## See also