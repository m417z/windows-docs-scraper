# IDCompositionAnimation::AddSinusoidal

## Description

Adds a sinusoidal segment to the animation function.

## Parameters

### `beginOffset`

Type: **double**

The offset, in seconds, from the beginning of the animation function to the point when this segment should take effect.

### `bias`

Type: **float**

A constant that is added to the sinusoidal.

### `amplitude`

Type: **float**

A scale factor that is applied to the sinusoidal.

### `frequency`

Type: **float**

A scale factor that is applied to the time offset, in Hertz.

### `phase`

Type: **float**

A constant that is added to the time offset, in degrees.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if any of the parameters are NaN, positive infinity, or negative infinity, or if the *beginOffset* parameter is negative.

Because animation segments must be added in increasing order, this method fails if the *beginOffset* parameter is less than or equal to the *beginOffset* parameter of the previous segment, if any.

This animation segment remains in effect until the begin time of the next segment in the animation function. If the animation function contains no more segments, this segment remains in effect indefinitely.

## See also

[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)