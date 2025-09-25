# PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 callback function

## Description

The PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 callback function inserts a signal for the specified synchronization objects in the specified context stream.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobject2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 Pfnd3dkmtSignalsynchronizationobject2;

// Definition

NTSTATUS Pfnd3dkmtSignalsynchronizationobject2
(
	const D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 *
)
{...}

```

## Remarks

## See also