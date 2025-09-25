# PFND3DKMT_DESTROYDEVICE callback function

## Description

The PFND3DKMT_DESTROYDEVICE callback function destroys a graphics context device.

## Parameters

### `unnamedParam1`

A pointer to a [D3DKMT_DESTROYDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroydevice) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_DESTROYDEVICE Pfnd3dkmtDestroydevice;

// Definition

NTSTATUS Pfnd3dkmtDestroydevice
(
	const D3DKMT_DESTROYDEVICE *
)
{...}

```