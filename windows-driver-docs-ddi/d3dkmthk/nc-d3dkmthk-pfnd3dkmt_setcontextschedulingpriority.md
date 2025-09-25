# PFND3DKMT_SETCONTEXTSCHEDULINGPRIORITY callback function

## Description

The PFND3DKMT_SETCONTEXTSCHEDULINGPRIORITY callback function sets the scheduling priority for a device context.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETCONTEXTSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setcontextschedulingpriority) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETCONTEXTSCHEDULINGPRIORITY Pfnd3dkmtSetcontextschedulingpriority;

// Definition

NTSTATUS Pfnd3dkmtSetcontextschedulingpriority
(
	const D3DKMT_SETCONTEXTSCHEDULINGPRIORITY *
)
{...}

```

## Remarks

## See also