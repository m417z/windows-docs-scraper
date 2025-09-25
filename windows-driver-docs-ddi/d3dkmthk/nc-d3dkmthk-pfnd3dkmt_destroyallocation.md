# PFND3DKMT_DESTROYALLOCATION callback function

## Description

The PFND3DKMT_DESTROYALLOCATION callback function releases allocations.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyallocation) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYALLOCATION Pfnd3dkmtDestroyallocation;

// Definition

NTSTATUS Pfnd3dkmtDestroyallocation
(
	const D3DKMT_DESTROYALLOCATION *
)
{...}

```