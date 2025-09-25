# _D3DHAL_DP2CREATELIGHT structure

## Description

The D3DHAL_DP2CREATELIGHT structure is used to create a light for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwIndex`

Specifies the index of the light being created.

## Remarks

The D3DHAL_DP2CREATELIGHT structure is used to hold the index into the light array. The driver should enlarge its light array as necessary to accommodate at least as many lights as specified by the index.

## See also

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)