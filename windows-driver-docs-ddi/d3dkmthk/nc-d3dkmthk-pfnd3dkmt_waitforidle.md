# PFND3DKMT_WAITFORIDLE callback function

## Description

The PFND3DKMT_WAITFORIDLE callback function waits for a display device to be idle.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORIDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforidle) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORIDLE Pfnd3dkmtWaitforidle;

// Definition

NTSTATUS Pfnd3dkmtWaitforidle
(
	const D3DKMT_WAITFORIDLE *
)
{...}

```

## Remarks

## See also