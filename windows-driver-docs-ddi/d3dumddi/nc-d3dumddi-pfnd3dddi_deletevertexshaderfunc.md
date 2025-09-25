# PFND3DDDI_DELETEVERTEXSHADERFUNC callback function

## Description

The **DeleteVertexShaderFunc** function cleans up driver-side resources that are associated with vertex shader code.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hShaderHandle* [in]

A handle to the vertex shader code object.

## Return value

**DeleteVertexShaderFunc** returns S_OK or an appropriate error result if the vertex shader code object is not successfully cleaned up.

## Remarks

The **DeleteVertexShaderFunc** function notifies the driver about the deletion of the vertex shader code object that the [CreateVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderfunc) function created. The driver can then clean up any driver-side resources that are associated with the vertex shader code.

## See also

[CreateVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderfunc)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)