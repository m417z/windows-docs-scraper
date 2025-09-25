# PFND3DKMT_DESTROYALLOCATION2 callback function

## Description

The PFND3DKMT_DESTROYALLOCATION2 callback function releases allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYALLOCATION2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyallocation2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYALLOCATION2 Pfnd3dkmtDestroyallocation2;

// Definition

NTSTATUS Pfnd3dkmtDestroyallocation2
(
	const D3DKMT_DESTROYALLOCATION2 *
)
{...}

```