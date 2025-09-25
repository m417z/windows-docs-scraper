# PFND3DKMT_INVALIDATEACTIVEVIDPN callback function

## Description

Pfnd3dkmtInvalidateactivevidpn invalidates the active video present network (VidPN) currently in use.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_INVALIDATEACTIVEVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidateactivevidpn) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_INVALIDATEACTIVEVIDPN Pfnd3dkmtInvalidateactivevidpn;

// Definition

NTSTATUS Pfnd3dkmtInvalidateactivevidpn
(
	const D3DKMT_INVALIDATEACTIVEVIDPN *
)
{...}

```

## Remarks

## See also