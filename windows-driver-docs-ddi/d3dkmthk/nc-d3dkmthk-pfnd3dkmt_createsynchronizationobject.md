# PFND3DKMT_CREATESYNCHRONIZATIONOBJECT callback function

## Description

The PFND3DKMT_CREATESYNCHRONIZATIONOBJECT callback function creates a synchronization object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_CREATESYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createsynchronizationobject) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATESYNCHRONIZATIONOBJECT Pfnd3dkmtCreatesynchronizationobject;

// Definition

NTSTATUS Pfnd3dkmtCreatesynchronizationobject
(
	D3DKMT_CREATESYNCHRONIZATIONOBJECT *
)
{...}

```