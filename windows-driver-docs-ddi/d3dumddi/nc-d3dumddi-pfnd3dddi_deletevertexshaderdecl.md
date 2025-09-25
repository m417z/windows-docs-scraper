# PFND3DDDI_DELETEVERTEXSHADERDECL callback function

## Description

The **DeleteVertexShaderDecl** function cleans up driver-side resources that are associated with the vertex shader declaration.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hShaderHandle* [in]

A handle to the vertex shader declaration object.

## Return value

**DeleteVertexShaderDecl** returns S_OK or an appropriate error result if the vertex shader declaration object is not successfully cleaned up.

## Remarks

The **DeleteVertexShaderDecl** function notifies the driver about the deletion of the vertex shader declaration object that the [CreateVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderdecl) function created. The driver can then clean up any driver-side resources that are associated with the vertex shader declaration.

## See also

[CreateVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderdecl)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)