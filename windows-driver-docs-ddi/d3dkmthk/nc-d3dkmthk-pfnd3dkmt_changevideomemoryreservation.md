# PFND3DKMT_CHANGEVIDEOMEMORYRESERVATION callback function

## Description

The PFND3DKMT_CHANGEVIDEOMEMORYRESERVATION callback function changes a video memory reservation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_CHANGEVIDEOMEMORYRESERVATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_changevideommemoryreservation) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CHANGEVIDEOMEMORYRESERVATION Pfnd3dkmtChangevideomemoryreservation;

// Definition

NTSTATUS Pfnd3dkmtChangevideomemoryreservation
(
	const D3DKMT_CHANGEVIDEOMEMORYRESERVATION *
)
{...}

```