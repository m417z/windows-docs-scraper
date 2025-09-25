# IDCompositionTranslateTransform::SetOffsetX(float)

## Description

Changes the value of the OffsetX property of a 2D translation transform. The OffsetX property specifies the distance to translate along the x-axis.

## Parameters

### `offsetX` [in]

Type: **float**

 The distance to translate along the x-axis, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method performs an affine transformation, which moves every point by a fixed distance in the same direction. It is similar to shifting the origin of the coordinate space.

This method fails if the *offsetX* parameter is NaN, positive infinity, or negative infinity.

If the OffsetX property was previously animated, this method removes the animation and sets the OffsetX property to the specified static value.

## See also

[IDCompositionTranslateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform)

[IDCompositionTranslateTransform::SetOffsetY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449131(v=vs.85))