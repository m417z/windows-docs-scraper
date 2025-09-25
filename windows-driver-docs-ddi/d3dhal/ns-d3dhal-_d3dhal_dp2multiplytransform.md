# _D3DHAL_DP2MULTIPLYTRANSFORM structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2MULTIPLYTRANSFORM structure is used to modify the transform matrix for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `xfrmType`

Specifies the current transform being modified.

|Value|Meaning|
|--- |--- |
|D3DTRANSFORMSTATE_PROJECTION|Specifies the current projection transformation.|
|D3DTRANSFORMSTATE_VIEW|Specifies the current view transformation.|
|D3DTRANSFORMSTATE_WORLD|Specifies the current world transformation.|

### `matrix`

Specifies the matrix used to modify the current transform.

## Remarks

This structure is used with hardware transform and lighting and is used by the Direct3D runtime to inform the driver about modifications to the various transformation matrices.

## See also

[D3DHAL_DP2SETTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2settransform)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)