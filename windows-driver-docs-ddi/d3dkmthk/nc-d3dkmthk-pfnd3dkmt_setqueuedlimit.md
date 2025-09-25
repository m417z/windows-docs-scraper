# PFND3DKMT_SETQUEUEDLIMIT callback function

## Description

The PFND3DKMT_SETQUEUEDLIMIT callback function sets or retrieves the limit for the number of operations of the given type that can be queued for the given device.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETQUEUEDLIMIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setqueuedlimit) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETQUEUEDLIMIT Pfnd3dkmtSetqueuedlimit;

// Definition

NTSTATUS Pfnd3dkmtSetqueuedlimit
(
	const D3DKMT_SETQUEUEDLIMIT *
)
{...}

```

## Remarks

## See also