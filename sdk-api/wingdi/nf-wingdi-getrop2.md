# GetROP2 function

## Description

The **GetROP2** function retrieves the foreground mix mode of the specified device context. The mix mode specifies how the pen or interior color and the color already on the screen are combined to yield a new color.

## Parameters

### `hdc` [in]

Handle to the device context.

## Return value

If the function succeeds, the return value specifies the foreground mix mode.

If the function fails, the return value is zero.

## Remarks

Following are the foreground mix modes.

| Mix mode | Description |
| --- | --- |
| R2_BLACK | Pixel is always 0. |
| R2_COPYPEN | Pixel is the pen color. |
| R2_MASKNOTPEN | Pixel is a combination of the colors common to both the screen and the inverse of the pen. |
| R2_MASKPEN | Pixel is a combination of the colors common to both the pen and the screen. |
| R2_MASKPENNOT | Pixel is a combination of the colors common to both the pen and the inverse of the screen. |
| R2_MERGENOTPEN | Pixel is a combination of the screen color and the inverse of the pen color. |
| R2_MERGEPEN | Pixel is a combination of the pen color and the screen color. |
| R2_MERGEPENNOT | Pixel is a combination of the pen color and the inverse of the screen color. |
| R2_NOP | Pixel remains unchanged. |
| R2_NOT | Pixel is the inverse of the screen color. |
| R2_NOTCOPYPEN | Pixel is the inverse of the pen color. |
| R2_NOTMASKPEN | Pixel is the inverse of the R2_MASKPEN color. |
| R2_NOTMERGEPEN | Pixel is the inverse of the R2_MERGEPEN color. |
| R2_NOTXORPEN | Pixel is the inverse of the R2_XORPEN color. |
| R2_WHITE | Pixel is always 1. |
| R2_XORPEN | Pixel is a combination of the colors in the pen and in the screen, but not in both. |

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetROP2](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setrop2)