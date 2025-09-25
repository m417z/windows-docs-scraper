# IDCompositionEffectGroup::SetOpacity(float)

## Description

Changes the value of the Opacity property.

## Parameters

### `opacity` [in]

Type: **float**

The new value of the Opacity property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The opacity is interpreted as completely transparent for all values less than or equal to 0, and as completely opaque for all values greater than or equal to 1. All values between 0 and 1 represent partial opacity.

This method fails if the *opacity* parameter is NaN, positive infinity, or negative infinity.

If the Opacity property was previously animated, this method removes the animation and sets the Opacity property to the specified static value.

## See also

[IDCompositionEffectGroup](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffectgroup)