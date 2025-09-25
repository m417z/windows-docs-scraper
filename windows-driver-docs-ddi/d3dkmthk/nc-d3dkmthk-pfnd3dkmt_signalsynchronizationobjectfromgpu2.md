# PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 callback function

## Description

The PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 callback function is used to signal a monitored fence.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromgpu2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 Pfnd3dkmtSignalsynchronizationobjectfromgpu2;

// Definition

NTSTATUS Pfnd3dkmtSignalsynchronizationobjectfromgpu2
(
	const D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 *
)
{...}

```

## Remarks

## See also