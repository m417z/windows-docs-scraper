# IMILBitmapEffectPrimitive::GetAffineMatrix

## Description

Retrieves the affine transformation matrix for the effect.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating the output pin through which to retrieve the affine matrix.

### `pMatrix` [in, out]

Type: **[MIL_MATRIX3X2D](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/ns-mileffects-milmatrix3x2d)***

When this method returns, contains a pointer to the affine matrix describing the effects transform.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.