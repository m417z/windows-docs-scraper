# IDCompositionArithmeticCompositeEffect::SetClampOutput

## Description

Specifies whether to clamp color values before the effect passes the values to the next effect in the graph.

## Parameters

### `clampoutput` [in]

Type: **BOOL**

A boolean value indicating whether to clamp the color values. A value of TRUE causes color values to be clamped between 0 and 1.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionArithmeticCompositeEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionarithmeticcompositeeffect)