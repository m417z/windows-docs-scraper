# PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 callback function

## Description

The PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 callback function inserts a wait for the specified synchronization objects in the specified context stream.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobject2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 Pfnd3dkmtWaitforsynchronizationobject2;

// Definition

NTSTATUS Pfnd3dkmtWaitforsynchronizationobject2
(
	D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 *
)
{...}

```

## Remarks

## See also