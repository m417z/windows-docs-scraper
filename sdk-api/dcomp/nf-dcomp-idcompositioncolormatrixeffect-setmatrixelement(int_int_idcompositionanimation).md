# IDCompositionColorMatrixEffect::SetMatrixElement(int,int,IDCompositionAnimation)

## Description

Sets an element of the color matrix.

## Parameters

### `row` [in]

Type: **int**

The row of the element.

### `column` [in]

Type: **int**

The column of the element.

### `animation` [in]

Type: **[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)***

An animation that represents how the element value changes over time. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioncolormatrixeffect)