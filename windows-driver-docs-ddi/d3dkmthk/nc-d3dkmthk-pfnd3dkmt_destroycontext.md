# PFND3DKMT_DESTROYCONTEXT callback function

## Description

Implemented by the client driver to destroy the specified graphics processing unit (GPU) context.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroycontext) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYCONTEXT Pfnd3dkmtDestroycontext;

// Definition

NTSTATUS Pfnd3dkmtDestroycontext
(
	const D3DKMT_DESTROYCONTEXT *
)
{...}

```