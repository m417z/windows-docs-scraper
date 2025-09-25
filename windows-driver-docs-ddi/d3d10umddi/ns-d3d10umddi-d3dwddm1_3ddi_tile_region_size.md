# D3DWDDM1_3DDI_TILE_REGION_SIZE structure

## Description

Specifies a tiled region.

## Members

### `NumTiles`

The number of tiles within the tiled region.

**Note** **NumTiles** must equal **Width** * **Height** * **Depth**.

### `bUseBox`

If **TRUE**, the tiled region is defined by the **Width**, **Height**, and **Depth** members. In this case, one update region cannot span mipmaps, although it can span array slices using the **Depth** member.

If **FALSE**, the **Width**, **Height**, and **Depth** members should be ignored, and the tiled region is defined by the **NumTiles** member. In this case, tiles are mapped linearly, first across the *x*-direction, then the *y*-direction, then (as applicable) across the *z*-direction, and then spilling over mipmaps and arrays in subresource order. This procedure is useful for mapping an entire resource at one time.

In either case, the starting location for the region within the resource
is specified as a separate parameter outside this structure.

### `Width`

The width (in the *x*-direction) of the tiled region. Used for buffer, 1-D, 2-D, and 3-D rendering.

### `Height`

The height (in the *y*-direction) of the tiled region. Used for 2-D and 3-D rendering.

### `Depth`

The depth (in the *z*-direction) of the tiled region. Used for 3-D rendering or for arrays. In the case of arrays, advancing in depth skips to the next slice of the same mipmap size.