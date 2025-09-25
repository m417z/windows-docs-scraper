# _D3DDDIARG_SETTRANSFORM structure

## Description

The D3DDDIARG_SETTRANSFORM structure describes how to set up a transform.

## Members

### `TransformType` [in]

A D3DTRANSFORMSTATETYPE-typed value that indicates the type of transform to set up. This member can be one of the following values.

| **Value** | **Meaning** |
|:--|:--|
| D3DTRANSFORMSTATE_PROJECTION | Projection transformation |
| D3DTRANSFORMSTATE_VIEW | View transformation |
| D3DTRANSFORMSTATE_WORLD | World transformation |

### `Matrix` [in]

A D3DMATRIX structure that describes the matrix that is used to set up the transform. For more information about D3DMATRIX, see the Microsoft Windows SDK documentation.

## Remarks

The Microsoft Direct3D runtime uses D3DDDIARG_SETTRANSFORM in a call to the user-mode display driver [SetTransform](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settransform) function to inform the driver about various hardware transformation and lighting matrices.

## See also

[SetTransform](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settransform)