# PFND3DKMT_GETPRESENTHISTORY callback function

## Description

Pfnd3dkmtGetpresenthistory retrieves copying history.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETPRESENTHISTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getpresenthistory) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETPRESENTHISTORY Pfnd3dkmtGetpresenthistory;

// Definition

NTSTATUS Pfnd3dkmtGetpresenthistory
(
	D3DKMT_GETPRESENTHISTORY *
)
{...}

```

## Remarks

## See also