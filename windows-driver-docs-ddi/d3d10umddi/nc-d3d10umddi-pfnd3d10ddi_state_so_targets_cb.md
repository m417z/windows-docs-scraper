# PFND3D10DDI_STATE_SO_TARGETS_CB callback function

## Description

The **pfnStateSoTargetsCb** function causes the Microsoft Direct3D 10 runtime to refresh the stream-out targets.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Direct3D 10 runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

## Remarks

The **pfnStateSoTargetsCb** function calls the user-mode display driver's [SoSetTargets](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_so_settargets) function with all of the currently set stream-output buffers.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)

[SoSetTargets](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_so_settargets)