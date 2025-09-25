# PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU callback function

## Description

The PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU callback function is used to signal a monitored fence.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromgpu) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU Pfnd3dkmtSignalsynchronizationobjectfromgpu;

// Definition

NTSTATUS Pfnd3dkmtSignalsynchronizationobjectfromgpu
(
	const D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU *
)
{...}

```

## Remarks

## See also