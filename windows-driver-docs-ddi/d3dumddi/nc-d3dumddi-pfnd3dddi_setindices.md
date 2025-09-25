# PFND3DDDI_SETINDICES callback function

## Description

The *SetIndices* function sets the current index buffer.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETINDICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setindices) structure that describes parameters for setting the current index buffer.

## Return value

*SetIndices* returns S_OK or an appropriate error result if the index buffer is not successfully set.

## Remarks

The Microsoft Direct3D runtime supplies a handle value of zero in the **hIndexBuffer** member of the [D3DDDIARG_SETINDICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setindices) structure that is pointed to by the *pData* parameter to clear the current index buffer. The driver should handle subsequent attempts to draw indexed primitives (before a new current index buffer is established) so that a crash does not occur. The debug version of your driver should display informative messages to the debug output stream when this error condition is detected.

## See also

[D3DDDIARG_SETINDICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setindices)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)