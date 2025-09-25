# XPS_TILE_MODE enumeration

## Description

Describes the tiling behavior of a tile brush.

## Constants

### `XPS_TILE_MODE_NONE:1`

Only the base tile is drawn.

### `XPS_TILE_MODE_TILE`

First, the base tile is drawn. Next, the remaining area is filled by repeating the base tile such that the right edge of one tile is adjacent to the left edge of the next, and similarly for bottom and top.

### `XPS_TILE_MODE_FLIPX`

The same as **XPS_TILE_MODE_TILE**, but alternate columns of tiles are flipped horizontally.

### `XPS_TILE_MODE_FLIPY`

The same as **XPS_TILE_MODE_TILE**, but alternate rows of tiles are flipped vertically.

### `XPS_TILE_MODE_FLIPXY`

The combination of the effects produced by **XPS_TILE_MODE_FLIPX** and **XPS_TILE_MODE_FLIPY**.

## Remarks

The following illustration shows the effect of each tile mode on how a tiled brush fills the output area.

![An illustration that shows different examples of different tile mode behaviors](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/TileMode.png)

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)