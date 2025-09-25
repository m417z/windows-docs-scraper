# PFND3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY callback function

## Description

The PFND3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY callback function sets the scheduling priority for a device context that is in the same process as other device contexts.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setcontextinprocessschedulingpriority) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY Pfnd3dkmtSetcontextinprocessschedulingpriority;

// Definition

NTSTATUS Pfnd3dkmtSetcontextinprocessschedulingpriority
(
	const D3DKMT_SETCONTEXTINPROCESSSCHEDULINGPRIORITY *
)
{...}

```

## Remarks

## See also