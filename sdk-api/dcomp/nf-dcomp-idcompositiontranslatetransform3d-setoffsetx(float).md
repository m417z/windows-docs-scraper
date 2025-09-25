# IDCompositionTranslateTransform3D::SetOffsetX(float)

## Description

Changes the value of the OffsetX property of a 3D translation transform effect. The OffsetX property specifies the distance to translate along the x-axis.

## Parameters

### `offsetX` [in]

Type: **float**

The distance to translate along the x-axis, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *offsetX* parameter is NaN, positive infinity, or negative infinity.

If the OffsetX property was previously animated, this method removes the animation and sets the OffsetX property to the specified static value.

## See also

[IDCompositionTranslateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform3d)

[IDCompositionTranslateTransform3D::SetOffsetY](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositiontranslatetransform3d-setoffsety(float))

[IDCompositionTranslateTransform3D::SetOffsetZ](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositiontranslatetransform3d-setoffsetz(float))