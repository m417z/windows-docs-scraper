# PFND3DKMT_PRESENT callback function

## Description

The PFND3DKMT_PRESENT callback function submits a present command to the Microsoft DirectX graphics kernel subsystem.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_PRESENT Pfnd3dkmtPresent;

// Definition

NTSTATUS Pfnd3dkmtPresent
(
	D3DKMT_PRESENT *
)
{...}

```

## Remarks

## See also