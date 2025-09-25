# PFND3DKMT_UNLOCK2 callback function

## Description

The PFND3DKMT_UNLOCK2 callback function unlocks a list of allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_UNLOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unlock2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UNLOCK2 Pfnd3dkmtUnlock2;

// Definition

NTSTATUS Pfnd3dkmtUnlock2
(
	const D3DKMT_UNLOCK2 *
)
{...}

```

## Remarks

## See also