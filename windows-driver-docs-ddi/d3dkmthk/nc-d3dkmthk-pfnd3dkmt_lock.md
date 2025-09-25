# PFND3DKMT_LOCK callback function

## Description

Pfnd3dkmtLock locks an entire allocation or specific pages within an allocation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_lock) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_LOCK Pfnd3dkmtLock;

// Definition

NTSTATUS Pfnd3dkmtLock
(
	D3DKMT_LOCK *
)
{...}

```

## Remarks

## See also