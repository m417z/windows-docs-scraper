# IDCompositionAnimation::AddCubic

## Description

Adds a cubic polynomial segment to the animation function.

## Parameters

### `beginOffset` [in]

Type: **double**

The offset, in seconds, from the beginning of the animation function to the point when this segment should take effect.

### `constantCoefficient` [in]

Type: **float**

The constant coefficient of the polynomial.

### `linearCoefficient` [in]

Type: **float**

The linear coefficient of the polynomial.

### `quadraticCoefficient` [in]

Type: **float**

The quadratic coefficient of the polynomial.

### `cubicCoefficient` [in]

Type: **float**

The cubic coefficient of the polynomial.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A cubic segment transitions time along a cubic polynomial. For a given time input (t), the output value is given by the following equation.

*x*(*t*) = *at*³ + *bt*² + *ct* + *d*

This method fails if any of the parameters are NaN, positive infinity, or negative infinity.

Because animation segments must be added in increasing order, this method fails if the *beginOffset* parameter is less than or equal to the *beginOffset* parameter of the previous segment, if any.

This animation segment remains in effect until the begin time of the next segment in the animation function. If the animation function contains no more segments, this segment remains in effect indefinitely.

If all coefficients except *constantCoefficient* are zero, the value of this segment remains constant over time, and the animation does not cause a recomposition for the duration of the segment.

#### Examples

The following example creates an animation function with two cubic polynomial segments.

```cpp
HRESULT DoAnimatedRotation(IDCompositionDevice *pDevice,
                           IDCompositionRotateTransform *pRotateTransform,
                           IDCompositionVisual *pVisual,
                           float animationTime)
{
    HRESULT hr = S_OK;
    IDCompositionAnimation *pAnimation = nullptr;

    // Create an animation object.
    hr = pDevice->CreateAnimation(&pAnimation);

    if (SUCCEEDED(hr))
    {
        // Create the animation function by adding cubic polynomial segments.
        // For a given time input (t), the output value is
        // a*t^3 + b* t^2 + c*t + d.
        //
        // The following segment will rotate the visual clockwise.
        pAnimation->AddCubic(
            0.0,                                // Begin offset
            0.0,                                // Constant coefficient - d
            (360.0f * 1.0f) / animationTime,    // Linear coefficient - c
            0.0,                                // Quadratic coefficient - b
            0.0);                               // Cubic coefficient - a

        // The following segment will rotate the visual counterclockwise.
        pAnimation->AddCubic(
            animationTime,
            0.0,
            -(360.0f * 1.0f) / animationTime,
            0.0,
            0.0);

        // Set the end of the animation.
        pAnimation->End(
            2 * animationTime,  // End offset
            0.0);               // End value

        // Apply the animation to the Angle property of the
        // rotate transform.
        hr = pRotateTransform->SetAngle(pAnimation);
    }

    if (SUCCEEDED(hr))
    {
        // Apply the rotate transform object to a visual.
        hr = pVisual->SetTransform(pRotateTransform);
    }

    if (SUCCEEDED(hr))
    {
        // Commit the changes to the composition.
        hr = pDevice->Commit();
    }

    SafeRelease(&pAnimation);

    return hr;
}

```

## See also

[Animation](https://learn.microsoft.com/windows/desktop/directcomp/animation)

[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)