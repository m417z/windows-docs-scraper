# PFND3DKMT_GETSHAREDPRIMARYHANDLE callback function

## Description

Pfnd3dkmtGetsharedprimaryhandle retrieves the global shared handle for the primary surface.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETSHAREDPRIMARYHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getsharedprimaryhandle) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETSHAREDPRIMARYHANDLE Pfnd3dkmtGetsharedprimaryhandle;

// Definition

NTSTATUS Pfnd3dkmtGetsharedprimaryhandle
(
	D3DKMT_GETSHAREDPRIMARYHANDLE *
)
{...}

```

## Remarks

## See also