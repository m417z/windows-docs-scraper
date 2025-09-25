# PFND3DDDI_MULTIPLYTRANSFORM callback function

## Description

The *MultiplyTransform* function modifies the current transform.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_MULTIPLYTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_multiplytransform) structure that describes how to modify the current transform.

## Return value

*MultiplyTransform* returns S_OK or an appropriate error result if the transform is not successfully modified.

## See also

[D3DDDIARG_MULTIPLYTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_multiplytransform)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)