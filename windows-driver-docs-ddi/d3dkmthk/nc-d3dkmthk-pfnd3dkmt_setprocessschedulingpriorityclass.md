# PFND3DKMT_SETPROCESSSCHEDULINGPRIORITYCLASS callback function

## Description

The PFND3DKMT_SETPROCESSSCHEDULINGPRIORITYCLASS callback function sets the scheduling priority for a process.

## Parameters

### `unnamedParam1:`

### `unnamedParam2:`

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETPROCESSSCHEDULINGPRIORITYCLASS Pfnd3dkmtSetprocessschedulingpriorityclass;

// Definition

NTSTATUS Pfnd3dkmtSetprocessschedulingpriorityclass
(
	HANDLE Arg1
	D3DKMT_SCHEDULINGPRIORITYCLASS Arg2
)
{...}

```

## Remarks

## See also