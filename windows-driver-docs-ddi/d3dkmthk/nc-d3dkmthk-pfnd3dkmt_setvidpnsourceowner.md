# PFND3DKMT_SETVIDPNSOURCEOWNER callback function

## Description

The PFND3DKMT_SETVIDPNSOURCEOWNER callback function sets and releases the video present source in the path of a video present network (VidPN) topology that owns the VidPN.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETVIDPNSOURCEOWNER Pfnd3dkmtSetvidpnsourceowner;

// Definition

NTSTATUS Pfnd3dkmtSetvidpnsourceowner
(
	const D3DKMT_SETVIDPNSOURCEOWNER *
)
{...}

```

## Remarks

## See also