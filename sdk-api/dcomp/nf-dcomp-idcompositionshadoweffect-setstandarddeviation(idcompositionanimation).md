# IDCompositionShadowEffect::SetStandardDeviation(IDCompositionAnimation)

## Description

Sets the amount of blur to be applied to the alpha channel of the image.

## Parameters

### `animation` [in]

Type: **[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)***

An animation that represents how the amount of blur to be applied to the alpha channel of the image changes over time.
You can compute the blur radius of the kernel by multiplying the standard deviation by 3.
The units of both the standard deviation and blur radius are DIPs.
This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionShadowEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionshadoweffect)