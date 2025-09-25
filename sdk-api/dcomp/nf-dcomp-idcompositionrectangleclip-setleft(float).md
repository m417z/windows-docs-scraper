# IDCompositionRectangleClip::SetLeft(float)

## Description

Changes the value of the Left property of a clip rectangle. The Left property specifies the x-coordinate of the upper-left corner of the clip rectangle.

## Parameters

### `left` [in]

Type: **float**

The new value of the Left property, in pixels. This parameter has a numerical limit of -2^21 to 2^21.
The API accepts numbers outside of this range, but they are always clamped to this range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if the *left* parameter is NaN, positive infinity, or negative infinity.

If the Left property was previously animated, this method removes the animation and sets the Left property to the specified static value.

## See also

[IDCompositionRectangleClip](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrectangleclip)