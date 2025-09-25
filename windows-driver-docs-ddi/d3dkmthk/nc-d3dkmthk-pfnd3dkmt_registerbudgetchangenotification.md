# PFND3DKMT_REGISTERBUDGETCHANGENOTIFICATION callback function

## Description

The PFND3DKMT_REGISTERBUDGETCHANGENOTIFICATION callback function receives notifications from a graphics framework (such as OpenGL).

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_REGISTERBUDGETCHANGENOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_registerbudgetchangenotification) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_REGISTERBUDGETCHANGENOTIFICATION Pfnd3dkmtRegisterbudgetchangenotification;

// Definition

NTSTATUS Pfnd3dkmtRegisterbudgetchangenotification
(
	D3DKMT_REGISTERBUDGETCHANGENOTIFICATION *
)
{...}

```

## Remarks

## See also