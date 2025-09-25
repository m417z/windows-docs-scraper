# IDCompositionAnimation::AddRepeat

## Description

Adds a repeat segment that causes the specified portion of an animation function to be repeated.

## Parameters

### `beginOffset` [in]

Type: **double**

The offset, in seconds, from the beginning of the animation to the point at which the repeat should begin.

### `durationToRepeat` [in]

Type: **double**

The duration, in seconds, of a portion of the animation immediately preceding the begin time that is specified by *beginOffset*. This is the portion that will be repeated.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method fails if any of the parameters are NaN, positive infinity, or negative infinity.

Because animation segments must be added in increasing order, this method fails if the *beginOffset* parameter is less than or equal to the *beginOffset* parameter of the previous segment. This method also fails if this is the first segment to be added to the animation function.

This animation segment remains in effect until the begin time of the next segment. If the animation function contains no more segments, this segment remains in effect indefinitely.

#### Examples

The following example creates an animation function that includes a repeat segment, and applies the animation to the x and y axes of a scale transform.

```cpp
HRESULT MyCreateAnimatedScaleTransform(IDCompositionDevice *pDevice,
                                       IDCompositionVisual *pVisual)
{
    HRESULT hr = S_OK;
    IDCompositionAnimation *pAnimation = nullptr;
    IDCompositionScaleTransform *pScaleTransform = nullptr;

    // Validate the pointers.
    if (pDevice == nullptr || pVisual == nullptr)
        return E_INVALIDARG;

    // Create an animation object.
    hr = pDevice->CreateAnimation(&pAnimation);
    if (SUCCEEDED(hr))
    {
        // Add segments to the animation function.
        pAnimation->AddCubic(0, 1, -0.5, 0, 0);
        pAnimation->AddRepeat(3.0, 3.0);
        pAnimation->End(10, .5);

        // Create a scale transform object.
          hr = pDevice->CreateScaleTransform(&pScaleTransform);
    }

    if (SUCCEEDED(hr))
    {
        // Apply the animation to the x and y axes of the scale transform.
        pScaleTransform->SetScaleX(pAnimation);
        pScaleTransform->SetScaleY(pAnimation);

        // Apply the scale transform to the visual.
        hr = pVisual->SetTransform(pScaleTransform);
    }

    if (SUCCEEDED(hr))
    {
        // Commit the composition for rendering.
        hr = pDevice->Commit();
    }

    // Clean up.
    SafeRelease(&pAnimation);
    SafeRelease(&pScaleTransform);

    return hr;
}

```

## See also

[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)