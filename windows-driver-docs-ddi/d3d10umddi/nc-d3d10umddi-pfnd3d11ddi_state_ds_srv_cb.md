# PFND3D11DDI_STATE_DS_SRV_CB callback function

## Description

The **pfnStateDsSrvCb** function causes the Microsoft Direct3D 11 runtime to refresh the constant shader resource view state for the domain shader.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Direct3D runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

### `unnamedParam2`

*Base* [in]

The beginning resource view for which the runtime should refresh state.

### `unnamedParam3`

*Count* [in]

The total number of resource views. The number can be -1, which specifies that the Direct3D runtime uses its high watermarks to substitute an optimal value (which is typically less than the maximum valid value for *Count*). However, no non-NULL binding exists in a slot larger than the optimal *Count* value.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D11DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_corelayer_devicecallbacks)