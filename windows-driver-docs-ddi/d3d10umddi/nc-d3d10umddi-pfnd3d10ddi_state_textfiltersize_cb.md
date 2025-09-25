# PFND3D10DDI_STATE_TEXTFILTERSIZE_CB callback function

## Description

The **pfnStateTextFilterSizeCb** function causes the Microsoft Direct3D 10 runtime to refresh the width and height of the monochrome convolution filter.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Direct3D 10 runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

## Remarks

The **pfnStateTextFilterSizeCb** function calls the user-mode display driver's [SetTextFilterSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_settextfiltersize) function with the current monochrome convolution filter settings.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)

[SetTextFilterSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_settextfiltersize)