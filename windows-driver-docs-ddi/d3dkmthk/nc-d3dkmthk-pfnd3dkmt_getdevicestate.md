# PFND3DKMT_GETDEVICESTATE callback function

## Description

Pfnd3dkmtGetdevicestate retrieves the state of a device.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETDEVICESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdevicestate) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETDEVICESTATE Pfnd3dkmtGetdevicestate;

// Definition

NTSTATUS Pfnd3dkmtGetdevicestate
(
	D3DKMT_GETDEVICESTATE *
)
{...}

```

## Remarks

## See also