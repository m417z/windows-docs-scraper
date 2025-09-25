# PFND3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY callback function

## Description

The Pfnd3dkmtGetcontextinprocessschedulingpriority callback function is called by an in-process (in-proc) Microsoft Direct3D composition device to retrieve the scheduling priority for a device context that is in the same process as other device contexts.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getcontextinprocessschedulingpriority) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY Pfnd3dkmtGetcontextinprocessschedulingpriority;

// Definition

NTSTATUS Pfnd3dkmtGetcontextinprocessschedulingpriority
(
	D3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY *
)
{...}

```

## Remarks

## See also