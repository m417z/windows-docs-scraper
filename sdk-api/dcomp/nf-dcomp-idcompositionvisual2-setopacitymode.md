# IDCompositionVisual2::SetOpacityMode

## Description

Sets the opacity mode for this visual.

## Parameters

### `mode` [in]

 The opacity mode to use when composing the visual to the screen.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The opacity mode affects how the Opacity property of an effect group object affects the composition of a visual sub-tree. DirectComposition supports two opacity modes: Layer and Multiply. In Layer mode, each visual sub-tree can be logically viewed as a bitmap that contains the opaque rasterization of that entire sub-tree, to which the opacity value is then applied. In this manner, overlapping opaque surfaces blend with the sub-tree’s background, but not with each other. In contrast, in Multiply mode the opacity is applied individually to each surface as it is composed, so surfaces blend with each other. Multiply mode is faster than Layer mode and always preferred if the visual tree contains entirely non-overlapping contents. However, Multiply mode may produce undesired visual results for overlapping elements.

By default, a visual inherits the opacity mode of its parent visual, which may inherit the opacity mode of its parent visual, and so on. A visual uses the DCOMPOSITION_OPACITY_MODE_LAYER mode if this method is never called for the visual, or if this method is called with DCOMPOSITION_OPACITY_MODE_INHERIT. If no visuals set the opacity mode, the default for the entire visual tree is DCOMPOSITION_OPACITY_MODE_LAYER.

If the *opacityMode* parameter is anything other than DCOMPOSITION_OPACITY_MODE_INHERIT, this visual's surfaces are composed with the specified opacity mode. In addition, this opacity mode becomes the new default for the children of the current visual. That is, if the opacity mode of this visual's children is unchanged or explicitly set to DCOMPOSITION_OPACITY_MODE_INHERIT, the surfaces the child visuals are composed using the opacity mode of this visual.

## See also

[IDCompositionEffectGroup::SetOpacity](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositioneffectgroup-setopacity(float))

[IDCompositionVisual2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual2)