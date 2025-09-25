# PFND3D11DDI_PERFORM_AMORTIZED_PROCESSING_CB callback function

## Description

The **pfnPerformAmortizedProcessingCb** function performs amortized processing.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Microsoft Direct3D runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

## Remarks

For more information about amortized processing, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D11DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_corelayer_devicecallbacks)