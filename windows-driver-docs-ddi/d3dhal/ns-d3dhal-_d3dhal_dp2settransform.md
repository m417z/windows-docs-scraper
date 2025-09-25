# _D3DHAL_DP2SETTRANSFORM structure

## Description

D3DHAL_DP2SETTRANSFORM structure is used to specify the transform state and matrix for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `xfrmType`

Specifies the type of transform being done.

|Value|Meaning|
|--- |--- |
|D3DTRANSFORMSTATE_PROJECTION|Specifies a projection transformation.|
|D3DTRANSFORMSTATE_VIEW|Specifies a view transformation.|
|D3DTRANSFORMSTATE_WORLD|Specifies a world transformation.|

### `matrix`

Specifies the matrix used to perform the transform.

## Remarks

This structure is used with hardware transform and lighting and is used by the Direct3D runtime to inform the driver about the various transformation matrices.

## See also

[D3DHAL_DP2MULTIPLYTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2multiplytransform)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)