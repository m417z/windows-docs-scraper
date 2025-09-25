# IDCompositionHueRotationEffect::SetAngle(float)

## Description

Sets the angle to rotate the hue.

## Parameters

### `amountDegrees` [in]

Type: **float**

The angle to rotate the hue. The effect calculates a color matrix based on the rotation angle (θ) according to the following matrix equations:

![Matrix equation](https://learn.microsoft.com/windows/win32/api/dcomp/images/hue_formula.png)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionHueRotationEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionhuerotationeffect)