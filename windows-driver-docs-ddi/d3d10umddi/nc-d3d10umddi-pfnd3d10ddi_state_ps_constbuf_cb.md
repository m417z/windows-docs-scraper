# PFND3D10DDI_STATE_PS_CONSTBUF_CB callback function

## Description

The **pfnStatePsConstBufCb** function causes the Microsoft Direct3D 10 runtime to refresh the pixel shader stage's bound constant buffers.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Direct3D 10 runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

### `unnamedParam2`

*Count* [in]

The total number of buffers to refresh. The number can be -1, which specifies that the Direct3D runtime will use its high watermarks to substitute an optimal value (which is typically less than the maximum valid value for *Count*). However, no non-NULL binding exists in a slot larger than the optimal *Count* value.

### `unnamedParam3`

*Base* [in]

The starting constant buffer to refresh.

## Remarks

The *Base* and *Count* parameters that the driver passes to the **pfnStatePsConstBufCb** function directly correspond to the *StartBuffer* and *NumBuffers* parameters that are passed to the driver's [PsSetConstantBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers) function.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)

[PsSetConstantBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setconstantbuffers)