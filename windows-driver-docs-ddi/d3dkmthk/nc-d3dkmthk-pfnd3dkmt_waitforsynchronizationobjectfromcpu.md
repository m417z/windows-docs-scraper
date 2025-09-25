# PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU callback function

## Description

The PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU callback function waits for a monitored fence to reach a certain value.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobjectfromcpu) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU Pfnd3dkmtWaitforsynchronizationobjectfromcpu;

// Definition

NTSTATUS Pfnd3dkmtWaitforsynchronizationobjectfromcpu
(
	const D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU *
)
{...}

```

## Remarks

## See also