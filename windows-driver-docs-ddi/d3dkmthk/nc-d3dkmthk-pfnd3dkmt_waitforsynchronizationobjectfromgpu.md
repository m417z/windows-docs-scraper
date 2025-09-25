# PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU callback function

## Description

The PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU callback function waits for a monitored fence to reach a certain value before processing subsequent context commands.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobjectfromgpu) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU Pfnd3dkmtWaitforsynchronizationobjectfromgpu;

// Definition

NTSTATUS Pfnd3dkmtWaitforsynchronizationobjectfromgpu
(
	const D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU *
)
{...}

```

## Remarks

## See also