# IDCompositionColorMatrixEffect::SetMatrix

## Description

Sets the matrix used by the effect to multiply the RGBA values of the image.

## Parameters

### `matrix` [in, ref]

Type: **const [D2D1_MATRIX_5X4_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-5x4-f)**

The matrix used by the effect to multiply the RGBA values of the image. The matrix is column major and is applied as shown in the following equation:

![Matrix equation](https://learn.microsoft.com/windows/win32/api/dcomp/images/color_matrix_formula.png)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioncolormatrixeffect)