# IDCompositionFilterEffect::SetInput

## Description

Sets the input at an index to the specified filter effect.

## Parameters

### `index` [in]

Type: **UINT**

Specifies the index the to apply the filter effect at.

### `input` [in, optional]

Type: **IUnknown***

The filter effect to apply.
The following effects are available:

* [IDCompositionAffineTransform2DEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionaffinetransform2deffect)
* [IDCompositionArithmeticCompositeEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionarithmeticcompositeeffect)
* [IDCompositionBlendEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionblendeffect)
* [IDCompositionBrightnessEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionbrightnesseffect)
* [IDCompositionColorMatrixEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioncolormatrixeffect)
* [IDCompositionCompositeEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioncompositeeffect)
* [IDCompositionFloodEffect](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn919732(v=vs.85))
* [IDCompositionGaussianBlurEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiongaussianblureffect)
* [IDCompositionHueRotationEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionhuerotationeffect)
* [IDCompositionLinearTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionlineartransfereffect)
* [IDCompositionSaturationEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsaturationeffect)
* [IDCompositionShadowEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionshadoweffect)
* [IDCompositionTableTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontabletransfereffect)
* [IDCompositionTurbulenceEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionturbulenceeffect)

### `flags` [in]

Type: **UINT**

Flags to apply to the filter effect.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionFilterEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionfiltereffect)