# PFND3DKMT_DESTROYOUTPUTDUPL callback function

## Description

The PFND3DKMT_DESTROYOUTPUTDUPL callback function destroys output duplicates.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROY_OUTPUTDUPL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroy_outputdupl) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYOUTPUTDUPL Pfnd3dkmtDestroyoutputdupl;

// Definition

NTSTATUS Pfnd3dkmtDestroyoutputdupl
(
	const D3DKMT_DESTROY_OUTPUTDUPL *
)
{...}

```