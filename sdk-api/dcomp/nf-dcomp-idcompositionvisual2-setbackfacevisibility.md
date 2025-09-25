## Description

Specifies whether or not surfaces that have 3D transformations applied to them should be displayed when facing away from the observer.

## Parameters

### `visibility`

[in]

The back face visibility to use when composing surfaces in this visual’s sub-tree to the screen.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The back face visibility property affects how surfaces that have 3D transformations applied are rendered.

By default, a visual inherits the back face visibility property of its parent visual, which may inherit the back face visibility property of its parent visual, and so on. A visual uses the DCOMPOSITION_BACKFACE_VISIBILITY_VISIBLE mode if this method is never called for the visual, or if this method is called with DCOMPOSITION_BACKFACE_VISIBILITY_INHERIT. If no visuals set the back face visibility property, the default for the entire visual tree is DCOMPOSITION_BACKFACE_VISIBILITY_VISIBLE.

If the *visibility* parameter is anything other than DCOMPOSITION_BACKFACE_VISIBILITY_INHERIT, this visual's surfaces are composed with the specified visibility mode. In addition, this visibility mode becomes the new default for the children of the current visual. That is, if the visibility mode of this visual's children is unchanged or explicitly set to DCOMPOSITION_BACKFACE_VISIBILITY_INHERIT, the surfaces the child visuals are composed using the visibility mode of this visual.

## See also

[DirectComposition Backface and D2D Batching](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/DCompV2BackfaceandD2DBatching)

[IDCompositionEffectGroup::SetTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositioneffectgroup-settransform3d)

[IDCompositionVisual2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual2)