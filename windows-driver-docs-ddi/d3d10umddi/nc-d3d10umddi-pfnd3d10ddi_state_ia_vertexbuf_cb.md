# PFND3D10DDI_STATE_IA_VERTEXBUF_CB callback function

## Description

The **pfnStateIaVertexBufCb** function causes the Microsoft Direct3D 10 runtime to refresh the set of vertex buffers that are bound to the input assembler.

## Parameters

### `unnamedParam1`

*hRuntimeDevice* [in]

A handle to a context for the core Direct3D 10 runtime. This handle is supplied to the driver in a call to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

### `unnamedParam2`

*Count* [in]

The total number of vertex buffers. The number can be -1, which specifies that the Direct3D runtime will use its high watermarks to substitute an optimal value (which is typically less than the maximum valid value for *Count*). However, no non-NULL binding exists in a slot larger than the optimal *Count* value.

### `unnamedParam3`

*Base* [in]

The beginning vertex buffer for which the runtime should refresh state.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_CORELAYER_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)