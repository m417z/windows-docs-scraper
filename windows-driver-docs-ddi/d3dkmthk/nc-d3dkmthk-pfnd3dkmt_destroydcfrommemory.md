# PFND3DKMT_DESTROYDCFROMMEMORY callback function

## Description

The PFND3DKMT_DESTROYDCFROMMEMORY callback function destroys a device context from memory.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYDCFROMMEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroydcfrommemory) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYDCFROMMEMORY Pfnd3dkmtDestroydcfrommemory;

// Definition

NTSTATUS Pfnd3dkmtDestroydcfrommemory
(
	const D3DKMT_DESTROYDCFROMMEMORY *
)
{...}

```