# PFND3DDDI_SETTRANSFORM callback function

## Description

The *SetTransform* function sets up a transform.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_settransform) structure that describes how to set up the transform.

## Return value

*SetTransform* returns S_OK or an appropriate error result if the transform is not successfully set up.

## See also

[D3DDDIARG_SETTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_settransform)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)