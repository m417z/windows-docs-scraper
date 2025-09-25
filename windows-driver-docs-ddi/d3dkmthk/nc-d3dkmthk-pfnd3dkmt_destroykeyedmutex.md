# PFND3DKMT_DESTROYKEYEDMUTEX callback function

## Description

The PFND3DKMT_DESTROYKEYEDMUTEX callback function destroys keyed mutex.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroykeyedmutex) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYKEYEDMUTEX Pfnd3dkmtDestroykeyedmutex;

// Definition

NTSTATUS Pfnd3dkmtDestroykeyedmutex
(
	const D3DKMT_DESTROYKEYEDMUTEX *
)
{...}

```