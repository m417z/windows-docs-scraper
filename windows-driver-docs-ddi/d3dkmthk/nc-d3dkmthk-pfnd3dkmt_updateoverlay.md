# PFND3DKMT_UPDATEOVERLAY callback function

## Description

PFND3DKMT_UPDATEOVERLAY callback function modifies a kernel-mode overlay object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_updateoverlay) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_UPDATEOVERLAY Pfnd3dkmtUpdateoverlay;

// Definition

NTSTATUS Pfnd3dkmtUpdateoverlay
(
	const D3DKMT_UPDATEOVERLAY *
)
{...}

```

## Remarks

## See also