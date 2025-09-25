# PFND3DKMT_LOCK2 callback function

## Description

Pfnd3dkmtLock2 locks an entire allocation or specific pages within an allocation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_LOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_lock2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_LOCK2 Pfnd3dkmtLock2;

// Definition

NTSTATUS Pfnd3dkmtLock2
(
	D3DKMT_LOCK2 *
)
{...}

```

## Remarks

## See also