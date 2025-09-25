# PFND3DKMT_SETVIDPNSOURCEOWNER2 callback function

## Description

The PFND3DKMT_SETVIDPNSOURCEOWNER2 callback function sets and releases the video present source in the path of a video present network (VidPN) topology that owns the VidPN.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETVIDPNSOURCEOWNER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETVIDPNSOURCEOWNER2 Pfnd3dkmtSetvidpnsourceowner2;

// Definition

NTSTATUS Pfnd3dkmtSetvidpnsourceowner2
(
	const D3DKMT_SETVIDPNSOURCEOWNER2 *
)
{...}

```

## Remarks

## See also