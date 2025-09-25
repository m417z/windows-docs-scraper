# ColorMatrixEffect::SetParameters

## Description

The **ColorMatrixEffect::SetParameters** method sets the 5x5 color matrix of this [ColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colormatrixeffect) object.

## Parameters

### `matrix` [in]

Type: **const [ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix)***

Pointer to a [ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix) object that specifies the 5x5 color matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[ColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colormatrixeffect)

[ColorMatrixEffect::GetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colormatrixeffect-getparameters)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)