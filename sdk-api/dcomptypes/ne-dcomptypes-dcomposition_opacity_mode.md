# DCOMPOSITION_OPACITY_MODE enumeration

## Description

Specifies how the effective opacity value of a visual is applied to that visual’s content and children.

## Constants

### `DCOMPOSITION_OPACITY_MODE_LAYER:0`

The target visual defines a logical layer into which its entire sub-tree is composed with a starting effective opacity of 1.0. The original opacity value is then used to blend the layer onto the visual’s background.

### `DCOMPOSITION_OPACITY_MODE_MULTIPLY:1`

The opacity value is multiplied with the effective opacity of the parent visual and the result is then individually applied to each piece of content in this visual’s sub-tree.

### `DCOMPOSITION_OPACITY_MODE_INHERIT:0xffffffff`

The opacity mode is the same as that of the target visual’s parent visual.

## See also

[IDCompositionEffectGroup::SetOpacity](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositioneffectgroup-setopacity(float))

IDCompositionVisual2::SetOpacityMode