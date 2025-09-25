# PFND3DKMT_WAITFORVERTICALBLANKEVENT2 callback function

## Description

The PFND3DKMT_WAITFORVERTICALBLANKEVENT2 callback function waits for the vertical blanking interval to occur.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORVERTICALBLANKEVENT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforverticalblankevent2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORVERTICALBLANKEVENT2 Pfnd3dkmtWaitforverticalblankevent2;

// Definition

NTSTATUS Pfnd3dkmtWaitforverticalblankevent2
(
	const D3DKMT_WAITFORVERTICALBLANKEVENT2 *
)
{...}

```

## Remarks

## See also