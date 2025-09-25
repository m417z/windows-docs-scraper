# IDCompositionVisual::SetEffect

## Description

Sets the Effect property of this visual. The Effect property modifies how the subtree that is rooted at this visual is blended with the background, and can apply a 3D perspective transform to the visual.

## Parameters

### `effect` [in, optional]

Type: **[IDCompositionEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffect)***

A pointer to an effect object. This parameter can be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method creates an implicit off-screen surface to which the subtree that is rooted at this visual is composed. The surface is used as one of the inputs to the specified effect. The output of the effect is composed directly to the composition target. Some effects also use the composition target as another implicit input. This is typically the case for compositional or blend effects such as opacity, where the composition target is considered to be the "background." In that case, any visuals that are "behind" the current visual are included in the composition target when the current visual is rendered and are considered to be the "background" that this visual composes to.

If this visual is not the root of a visual tree and one of its ancestors also has an effect applied to it, the off-screen surface created by the closest ancestor is the composition target to which this visual's effect is composed. Otherwise, the composition target is the root composition target. As a consequence, the background for compositional and blend effects includes only the visuals up to the closest ancestor that itself has an effect. Conversely, any effects applied to visuals under the current visual use the newly created off-screen surface as the background, which may affect how those visuals ultimately compose on top of what the end user perceives as being "behind" those visuals.

If the *effect* parameter is NULL, no bitmap effect is applied to this visual. Any previous effects that were associated with this visual are removed. The off-screen surface is also removed and the visual subtree is composed directly to the parent composition target, which may also affect how compositional or blend effects under this visual are rendered.

This method fails if *effect* is an invalid pointer or if it was not created by the same [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface that created this visual. The interface cannot be a custom implementation; only interfaces created by Microsoft DirectComposition can be used with this method.

## See also

[IDCompositionEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffect)

[IDCompositionEffectGroup](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffectgroup)

[IDCompositionMatrixTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionmatrixtransform3d)

[IDCompositionRotateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrotatetransform3d)

[IDCompositionScaleTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionscaletransform3d)

[IDCompositionTranslateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform3d)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)