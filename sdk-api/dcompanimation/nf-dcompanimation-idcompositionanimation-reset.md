# IDCompositionAnimation::Reset

## Description

Resets the animation function so that it contains no segments.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method returns the animation function to a clean state, as when the animation was first constructed. After this method is called, the next segment to be added becomes the first segment of the animation function. Because it is the first segment, it can have any non-negative beginning offset.

## See also

[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)