# PFND3DKMT_CREATESYNCHRONIZATIONOBJECT2 callback function

## Description

The PFND3DKMT_CREATESYNCHRONIZATIONOBJECT2 callback function creates a synchronization object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createsynchronizationobject2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATESYNCHRONIZATIONOBJECT2 Pfnd3dkmtCreatesynchronizationobject2;

// Definition

NTSTATUS Pfnd3dkmtCreatesynchronizationobject2
(
	D3DKMT_CREATESYNCHRONIZATIONOBJECT2 *
)
{...}

```