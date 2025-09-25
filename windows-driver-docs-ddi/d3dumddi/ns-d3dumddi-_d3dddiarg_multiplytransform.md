# _D3DDDIARG_MULTIPLYTRANSFORM structure

## Description

The D3DDDIARG_MULTIPLYTRANSFORM structure describes how to modify the current transform.

## Members

### `TransformType` [in]

A D3DTRANSFORMSTATETYPE-typed value that indicates the type of the transform that is being modified. This member can be one of the following values.

| **Value** | **Meaning** |
|:--|:--|
| D3DTRANSFORMSTATE_PROJECTION | Projection transformation |
| D3DTRANSFORMSTATE_VIEW | View transformation |
| D3DTRANSFORMSTATE_WORLD | World transformation |

### `Matrix` [in]

A D3DMATRIX structure that describes the matrix that is used to modify the current transform. For more information about D3DMATRIX, see the Microsoft Windows SDK documentation.

## Remarks

The Microsoft Direct3D runtime uses D3DDDIARG_MULTIPLYTRANSFORM in a call to the user-mode display driver's [MultiplyTransform](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_multiplytransform) function to inform the driver about modifications to the various transformation matrices.

## See also

[MultiplyTransform](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_multiplytransform)