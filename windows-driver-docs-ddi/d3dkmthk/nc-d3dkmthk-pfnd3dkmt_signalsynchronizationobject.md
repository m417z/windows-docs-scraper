# PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT callback function

## Description

The PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT callback function inserts a signal for the specified synchronization objects in the specified context stream.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SIGNALSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobject) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT Pfnd3dkmtSignalsynchronizationobject;

// Definition

NTSTATUS Pfnd3dkmtSignalsynchronizationobject
(
	const D3DKMT_SIGNALSYNCHRONIZATIONOBJECT *
)
{...}

```

## Remarks

## See also