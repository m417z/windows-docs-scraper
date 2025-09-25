# D2D1_VERTEX_OPTIONS enumeration

## Description

Describes flags that influence how the renderer interacts with a custom vertex shader.

## Constants

### `D2D1_VERTEX_OPTIONS_NONE:0`

The logical equivalent of having no flags set.

### `D2D1_VERTEX_OPTIONS_DO_NOT_CLEAR:1`

If this flag is set, the renderer assumes that the vertex shader will cover the entire region of interest with vertices and need not clear the destination render target. If this flag is not set, the renderer assumes that the vertices do not cover the entire region interest and must clear the render target to transparent black first.

### `D2D1_VERTEX_OPTIONS_USE_DEPTH_BUFFER:2`

The renderer will use a depth buffer when rendering custom vertices. The depth buffer will be used for calculating occlusion information. This can result in the renderer output being draw-order dependent if it contains transparency.

### `D2D1_VERTEX_OPTIONS_ASSUME_NO_OVERLAP:4`

Indicates that custom vertices do not overlap each other.

### `D2D1_VERTEX_OPTIONS_FORCE_DWORD:0xffffffff`

## See also

[D2D1_BLEND_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_blend_description)

[ID2D1BlendTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1blendtransform)