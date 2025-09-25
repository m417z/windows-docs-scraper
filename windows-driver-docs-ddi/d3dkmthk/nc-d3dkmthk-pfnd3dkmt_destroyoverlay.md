# PFND3DKMT_DESTROYOVERLAY callback function

## Description

The D3dkmtDestroyOverlay callback function disables overlay hardware and deletes the specified overlay handle.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyoverlay) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYOVERLAY Pfnd3dkmtDestroyoverlay;

// Definition

NTSTATUS Pfnd3dkmtDestroyoverlay
(
	const D3DKMT_DESTROYOVERLAY *
)
{...}

```