# PFND3DKMT_QUERYHYBRIDLISTVALUE callback function

## Description

The PFND3DKMT_QUERYHYBRIDLISTVALUE callback function queries for the hybrid list value.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_HYBRID_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_hybrid_list) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYHYBRIDLISTVALUE Pfnd3dkmtQueryhybridlistvalue;

// Definition

NTSTATUS Pfnd3dkmtQueryhybridlistvalue
(
	D3DKMT_HYBRID_LIST *
)
{...}

```

## Remarks

## See also