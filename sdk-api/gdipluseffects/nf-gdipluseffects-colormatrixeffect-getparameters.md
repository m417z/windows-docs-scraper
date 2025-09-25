# ColorMatrixEffect::GetParameters

## Description

The **ColorMatrixEffect::GetParameters** method gets the elements of the current 5x5 color matrix of this [ColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colormatrixeffect) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix) structure.

### `matrix` [out]

Type: **[ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix)***

Pointer to a [ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix) structure that receives the elements of the color matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[ColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colormatrixeffect)

[ColorMatrixEffect::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colormatrixeffect-setparameters)