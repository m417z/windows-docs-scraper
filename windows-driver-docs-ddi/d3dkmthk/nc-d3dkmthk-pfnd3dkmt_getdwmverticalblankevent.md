# PFND3DKMT_GETDWMVERTICALBLANKEVENT callback function

## Description

Pfnd3dkmtGetdwmverticalblankevent gets DWM (desktop windows manager) vertical blank event.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETVERTICALBLANKEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getverticalblankevent) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETDWMVERTICALBLANKEVENT Pfnd3dkmtGetdwmverticalblankevent;

// Definition

NTSTATUS Pfnd3dkmtGetdwmverticalblankevent
(
	const D3DKMT_GETVERTICALBLANKEVENT *
)
{...}

```

## Remarks

## See also