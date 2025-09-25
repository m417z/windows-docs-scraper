# D2D1_VERTEX_USAGE enumeration

## Description

Indicates whether the vertex buffer changes infrequently or frequently.

## Constants

### `D2D1_VERTEX_USAGE_STATIC:0`

The created vertex buffer is updated infrequently.

### `D2D1_VERTEX_USAGE_DYNAMIC:1`

The created vertex buffer is changed frequently.

### `D2D1_VERTEX_USAGE_FORCE_DWORD:0xffffffff`

## Remarks

If a dynamic vertex buffer is created, Direct2D will not necessarily map the buffer directly to a Direct3D vertex buffer. Instead, a system memory copy can be copied to the rendering engine vertex buffer as the effects are rendered.

## See also

[D2D1_BLEND_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_blend_description)

[ID2D1BlendTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1blendtransform)