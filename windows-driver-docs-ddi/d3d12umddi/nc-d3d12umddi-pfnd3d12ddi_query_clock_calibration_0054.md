# PFND3D12DDI_QUERY_CLOCK_CALIBRATION_0054 callback function

## Description

Queries for clock calibration information.

## Parameters

### `unnamedParam1`

The device to query clock information for.

### `unnamedParam2`

A handle to the command queue.

### `pClockData`

Pointer to a [D3D12DDI_GPUCLOCKDATA_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_gpuclockdata_0054) structure that contains the output frequency, GPU clock, and CPU clock on the specified engine.

## Prototype

```
//Declaration

PFND3D12DDI_QUERY_CLOCK_CALIBRATION_0054 Pfnd3d12ddiQueryClockCalibration0054;

// Definition

void Pfnd3d12ddiQueryClockCalibration0054
(
	D3D12DDI_HDEVICE Arg1
	D3D12DDI_HCOMMANDQUEUE Arg2
	D3D12DDI_GPUCLOCKDATA_0054 *pClockData
)
{...}

```

## Remarks

## See also