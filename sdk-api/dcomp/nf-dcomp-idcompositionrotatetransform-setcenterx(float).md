# IDCompositionRotateTransform::SetCenterX

## Description

Changes the value of the CenterX property of a 2D rotation transform. The CenterX property specifies the x-coordinate of the point about which the rotation is performed.

## Parameters

### `centerX` [in]

Type: **float**

The new x-coordinate of the center point.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *centerX* parameter is NaN, positive infinity, or negative infinity.

If the CenterX property was previously animated, this method removes the animation and sets the CenterX property to the specified static value.

## See also

[IDCompositionRotateTransform](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform)

[IDCompositionRotateTransform::SetCenterY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh448988(v=vs.85))