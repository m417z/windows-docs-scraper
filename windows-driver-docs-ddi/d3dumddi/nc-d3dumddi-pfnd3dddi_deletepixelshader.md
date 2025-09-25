# PFND3DDDI_DELETEPIXELSHADER callback function

## Description

The **DeletePixelShader** function cleans up driver-side resources that are associated with pixel shader code.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hShaderHandle* [in]

A handle to the pixel shader code object.

## Return value

**DeletePixelShader** returns S_OK or an appropriate error result if the pixel shader code object is not successfully cleaned up.

## Remarks

The **DeletePixelShader** function notifies the driver about the deletion of the pixel shader code object that the [CreatePixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpixelshader) function created. The driver can then clean up any driver-side resources that are associated with the pixel shader code.

## See also

[CreatePixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpixelshader)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)