# PFND3DKMT_SETALLOCATIONPRIORITY callback function

## Description

The PFND3DKMT_SETALLOCATIONPRIORITY callback function sets the priority level of a resource or list of allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETALLOCATIONPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setallocationpriority) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETALLOCATIONPRIORITY Pfnd3dkmtSetallocationpriority;

// Definition

NTSTATUS Pfnd3dkmtSetallocationpriority
(
	const D3DKMT_SETALLOCATIONPRIORITY *
)
{...}

```

## Remarks

## See also