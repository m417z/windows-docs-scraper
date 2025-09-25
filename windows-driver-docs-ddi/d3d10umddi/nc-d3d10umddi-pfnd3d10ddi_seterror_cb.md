# PFND3D10DDI_SETERROR_CB callback function

## Description

The **pfnSetErrorCb** function sets the return error code of a user-mode display driver's function.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Microsoft Direct3D 10 runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

### `unnamedParam2`

*hResult* [in]

An HRESULT value that specifies the error to set for a driver function.

## Remarks

A user-mode display driver can call **pfnSetErrorCb** many times for each driver invocation. For the driver's functions that do not return status codes, the driver uses **pfnSetErrorCb** to return error information to the Direct3D runtime.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)