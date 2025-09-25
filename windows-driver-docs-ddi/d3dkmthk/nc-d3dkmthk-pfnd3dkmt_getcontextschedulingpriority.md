# PFND3DKMT_GETCONTEXTSCHEDULINGPRIORITY callback function

## Description

The Pfnd3dkmtGetcontextschedulingpriority retrieves the scheduling priority for a device context.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETCONTEXTSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getcontextschedulingpriority) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETCONTEXTSCHEDULINGPRIORITY Pfnd3dkmtGetcontextschedulingpriority;

// Definition

NTSTATUS Pfnd3dkmtGetcontextschedulingpriority
(
	D3DKMT_GETCONTEXTSCHEDULINGPRIORITY *
)
{...}

```

## Remarks

## See also