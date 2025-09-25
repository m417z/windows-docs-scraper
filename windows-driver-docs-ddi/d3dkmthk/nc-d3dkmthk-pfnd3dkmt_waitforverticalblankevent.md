# PFND3DKMT_WAITFORVERTICALBLANKEVENT callback function

## Description

The PFND3DKMT_WAITFORVERTICALBLANKEVENT callback function waits for the vertical blanking interval to occur.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORVERTICALBLANKEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforverticalblankevent) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORVERTICALBLANKEVENT Pfnd3dkmtWaitforverticalblankevent;

// Definition

NTSTATUS Pfnd3dkmtWaitforverticalblankevent
(
	const D3DKMT_WAITFORVERTICALBLANKEVENT *
)
{...}

```

## Remarks

## See also