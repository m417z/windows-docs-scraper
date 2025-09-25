# PFND3DKMT_RECLAIMALLOCATIONS2 callback function

## Description

The PFND3DKMT_RECLAIMALLOCATIONS2 callback function reclaims video memory allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_RECLAIMALLOCATIONS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_reclaimallocations2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_RECLAIMALLOCATIONS2 Pfnd3dkmtReclaimallocations2;

// Definition

NTSTATUS Pfnd3dkmtReclaimallocations2
(
	D3DKMT_RECLAIMALLOCATIONS2 *
)
{...}

```

## Remarks

## See also