# PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT callback function

## Description

The PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT callback function inserts a wait for the specified synchronization objects in the specified context stream.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobject) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT Pfnd3dkmtWaitforsynchronizationobject;

// Definition

NTSTATUS Pfnd3dkmtWaitforsynchronizationobject
(
	D3DKMT_WAITFORSYNCHRONIZATIONOBJECT *
)
{...}

```

## Remarks

## See also