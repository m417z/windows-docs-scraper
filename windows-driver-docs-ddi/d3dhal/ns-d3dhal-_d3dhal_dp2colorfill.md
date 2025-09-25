# _D3DHAL_DP2COLORFILL structure

## Description

 DirectX 9.0 and later versions only.

D3DHAL_DP2COLORFILL is used for color-fill operations when [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) responds to the D3DDP2OP_COLORFILL command token.

## Members

### `dwSurface`

Specifies the handle to the surface to be filled.

### `rRect`

Specifies a RECTL structure that specifies the upper left and lower right points of a rectangle on the surface to be filled.

### `Color`

Specifies a D3DCOLOR for the color type.

## Remarks

Because DirectX 9.0 and later drivers are required to support the D3DDP2OP_COLORFILL command token, they are not required to expose a capability bit that indicates such support.

Display drivers must convert input color values for the ARGB and YUV classes of color formats. For color-fill operations, input color values are specified in the **Color** member. For more information, see [Handling Color Values for Pixel Formats](https://learn.microsoft.com/windows-hardware/drivers/display/handling-color-values-for-pixel-formats).

When the runtime calls a driver's **DdBlt** function to perform a color-fill operation, the runtime converts the D3DCOLOR value to an explicit pixel value if the runtime supports the format of that D3DCOLOR value. If the runtime does not support the format, the D3DCOLOR value is passed directly to the driver.

For more information about D3DCOLOR, see the DirectX SDK documentation.

## See also

D3DDP2OP_COLORFILL

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[DdBlt](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_surfcb_blt)