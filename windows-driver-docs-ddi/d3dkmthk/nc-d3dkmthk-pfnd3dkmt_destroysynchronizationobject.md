# PFND3DKMT_DESTROYSYNCHRONIZATIONOBJECT callback function

## Description

The PFND3DKMT_DESTROYSYNCHRONIZATIONOBJECT callback function destroys synchronization object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroysynchronizationobject) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYSYNCHRONIZATIONOBJECT Pfnd3dkmtDestroysynchronizationobject;

// Definition

NTSTATUS Pfnd3dkmtDestroysynchronizationobject
(
	const D3DKMT_DESTROYSYNCHRONIZATIONOBJECT *
)
{...}

```