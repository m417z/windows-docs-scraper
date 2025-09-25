# IDCompositionTurbulenceEffect::SetStitchable

## Description

Specifies whether stitching is on or off.

## Parameters

### `stitchable` [in]

Type: **BOOL**

A boolean value that specifies whether stitching is on or off. The base frequency is adjusted so that the output bitmap can be stitched.
This is useful if you want to tile multiple copies of the turbulence effect output.
If this value is TRUE, the output bitmap can be tiled (using the tile effect) without the appearance of seams and the base frequency is adjusted so that output bitmap can be stitched.
If this value is FALSE, the base frequency is not adjusted, so seams may appear between tiles if the bitmap is tiled.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionTurbulenceEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionturbulenceeffect)