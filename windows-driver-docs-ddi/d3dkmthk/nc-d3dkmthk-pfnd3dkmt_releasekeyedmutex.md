# PFND3DKMT_RELEASEKEYEDMUTEX callback function

## Description

The PFND3DKMT_RELEASEKEYEDMUTEX callback function releases a keyed mutex object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_RELEASEKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_releasekeyedmutex) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_RELEASEKEYEDMUTEX Pfnd3dkmtReleasekeyedmutex;

// Definition

NTSTATUS Pfnd3dkmtReleasekeyedmutex
(
	D3DKMT_RELEASEKEYEDMUTEX *
)
{...}

```

## Remarks

## See also