# PFND3DKMT_GETALLOCATIONPRIORITY callback function

## Description

The Pfnd3dkmtGetallocationpriority callback function gets allocation priority.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETALLOCATIONPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getallocationpriority) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETALLOCATIONPRIORITY Pfnd3dkmtGetallocationpriority;

// Definition

NTSTATUS Pfnd3dkmtGetallocationpriority
(
	const D3DKMT_GETALLOCATIONPRIORITY *
)
{...}

```

## Remarks

## See also