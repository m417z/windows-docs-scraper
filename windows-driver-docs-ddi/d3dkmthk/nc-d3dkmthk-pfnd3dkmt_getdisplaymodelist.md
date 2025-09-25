# PFND3DKMT_GETDISPLAYMODELIST callback function

## Description

Pfnd3dkmtGetdisplaymodelist retrieves a list of available display modes, including modes with extended format.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETDISPLAYMODELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdisplaymodelist) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETDISPLAYMODELIST Pfnd3dkmtGetdisplaymodelist;

// Definition

NTSTATUS Pfnd3dkmtGetdisplaymodelist
(
	D3DKMT_GETDISPLAYMODELIST *
)
{...}

```

## Remarks

## See also