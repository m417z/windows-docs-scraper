# IDCompositionAnimation::End

## Description

Adds an end segment that marks the end of an animation function.

## Parameters

### `endOffset` [in]

Type: **double**

The offset, in seconds, from the beginning of the animation function to the point when the function ends.

### `endValue` [in]

Type: **float**

The final value of the animation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

When the specified offset is reached, the property or properties affected by this animation are set to the specified final value, and then the animation stops. If no end segment is added, the final segment of the animation function runs indefinitely. Calling this method is semantically identical to making the last segment of the animation function a cubic polynomial where the cubic, quadratic, and linear coefficients are all zeros, and the constant coefficient is the desired final value.

Because animation segments must be added in increasing order, this method fails if the *endOffset* parameter is less than or equal to the *beginOffset* parameter of the previous segment. This method also fails if this is the first segment to be added to the animation function.

After this method is called, all methods on this animation object fail except the [IDCompositionAnimation::Reset](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nf-dcompanimation-idcompositionanimation-reset) method.

## See also

[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)