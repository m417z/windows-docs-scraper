# IDCompositionVisual::SetCompositeMode

## Description

Sets the blending mode for this visual.

## Parameters

### `compositeMode` [in]

Type: **[DCOMPOSITION_COMPOSITE_MODE](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_composite_mode)**

The blending mode to use when composing the visual to the screen.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The composite mode determines how visual's bitmap is blended with the screen. By default, the visual is blended with "source over" semantics; that is, the colors are blended with per-pixel transparency.

## See also

[IDCompositionEffectGroup](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffectgroup)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)