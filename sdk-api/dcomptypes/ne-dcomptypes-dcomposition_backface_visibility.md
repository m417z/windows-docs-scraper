## Description

Specifies the backface visibility to be applied to a visual.

## Constants

### `DCOMPOSITION_BACKFACE_VISIBILITY_VISIBLE:0`

Surfaces in this visual's sub-tree are visible regardless of transformation.

### `DCOMPOSITION_BACKFACE_VISIBILITY_HIDDEN:1`

Surfaces in this visual's sub-tree are only visible when facing the observer.

### `DCOMPOSITION_BACKFACE_VISIBILITY_INHERIT:0xffffffff`

The back face visibility is the same as that of the target visual's parent visual.

## See also

[DirectComposition Backface and D2D Batching](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/DCompV2BackfaceandD2DBatching)

[IDCompositionVisual2::SetBackFaceVisibility](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual2-setbackfacevisibility)