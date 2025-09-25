# PFND3DKMT_OPENSYNCHRONIZATIONOBJECT callback function

## Description

The PFND3DKMT_OPENSYNCHRONIZATIONOBJECT callback function opens a kernel-mode synchronization object.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensynchronizationobject) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OPENSYNCHRONIZATIONOBJECT Pfnd3dkmtOpensynchronizationobject;

// Definition

NTSTATUS Pfnd3dkmtOpensynchronizationobject
(
	D3DKMT_OPENSYNCHRONIZATIONOBJECT *
)
{...}

```

## Remarks

## See also