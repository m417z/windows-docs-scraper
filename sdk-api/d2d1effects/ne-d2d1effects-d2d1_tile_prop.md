# D2D1_TILE_PROP enumeration

## Description

Identifiers for properties of the [Tile effect](https://learn.microsoft.com/windows/desktop/Direct2D/tile).

## Constants

### `D2D1_TILE_PROP_RECT:0`

The region of the image to be tiled. This property is a [D2D1_VECTOR_4F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_4f) defined as: (left, top, right, bottom). The units are in DIPs.

The type is [D2D1_VECTOR_4F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_4f).

The default is {0.0f, 0.0f, 100.0f, 100.0f}.

### `D2D1_TILE_PROP_FORCE_DWORD:0xffffffff`