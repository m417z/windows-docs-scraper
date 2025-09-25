# _DXGK_GPUCLOCKDATA_FLAGS structure

## Description

Contains information about the GPU clock data flags.

## Members

### `ContextManagementProcessor`

A context management processor flag.

### `Reserved`

Reserved.

### `Value`

value of the GPU clock data.

## Remarks

As long as the GPU is powered on:

* The context management processor for a GPU node is expected to have access to a clock that is always counting.
* The clock frequency on the context management processor is expected to remain constant.

When a GPU node is initialized, the OS calibrates the GPU clock against the CPU clock using [DxgkDdiCalibrateGpuClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_calibrategpuclock) function with the ContextManagementProcessor flag. The flag differentiates between using DdiCalibrateGpuClock() to obtain the underlying GPU engine clock, or to obtain the context management processor clock, that may be different from the GPU engine clock.

## See also

[DxgkDdiCalibrateGpuClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_calibrategpuclock)