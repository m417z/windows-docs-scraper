# PFND3DKMT_QUERYCLOCKCALIBRATION callback function

## Description

The PFND3DKMT_QUERYCLOCKCALIBRATION callback function queries clock calibration.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYCLOCKCALIBRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmt_queryclockcalibration) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYCLOCKCALIBRATION Pfnd3dkmtQueryclockcalibration;

// Definition

NTSTATUS Pfnd3dkmtQueryclockcalibration
(
	D3DKMT_QUERYCLOCKCALIBRATION *
)
{...}

```

## Remarks

## See also