# PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU callback function

## Description

The PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU callback function enables a driver to signal a monitored fence.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromcpu) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU Pfnd3dkmtSignalsynchronizationobjectfromcpu;

// Definition

NTSTATUS Pfnd3dkmtSignalsynchronizationobjectfromcpu
(
	const D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU *
)
{...}

```

## Remarks

## See also