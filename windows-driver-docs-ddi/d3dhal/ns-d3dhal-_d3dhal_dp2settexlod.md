# _D3DHAL_DP2SETTEXLOD structure

## Description

The D3DHAL_DP2SETTEXLOD structure is used to set the level of detail (LOD) for MIP maps when the D3DDP2OP_SETTEXLOD command is sent to [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwDDSurface`

Specifies a handle to a surface chain.

### `dwLOD`

Controls the maximum MIP level loaded into video memory. Therefore, if the most detailed MIP map in the chain has dimensions 256x256, setting the maximum level to 2 means that the largest MIP map ever present in video memory has dimensions 64x64.

## Remarks

 Used only for driver-managed textures. This structure contains a surface handle to the MIP map and the maximum level of detail to set.

## See also

D3DDP2OP_SETTEXLOD

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)