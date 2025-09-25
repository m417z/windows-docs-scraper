# PFND3DKMT_POLLDISPLAYCHILDREN callback function

## Description

The PFND3DKMT_POLLDISPLAYCHILDREN callback function queries for connectivity status of all child devices of the given adapter.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_POLLDISPLAYCHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_polldisplaychildren) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_POLLDISPLAYCHILDREN Pfnd3dkmtPolldisplaychildren;

// Definition

NTSTATUS Pfnd3dkmtPolldisplaychildren
(
	const D3DKMT_POLLDISPLAYCHILDREN *
)
{...}

```

## Remarks

## See also