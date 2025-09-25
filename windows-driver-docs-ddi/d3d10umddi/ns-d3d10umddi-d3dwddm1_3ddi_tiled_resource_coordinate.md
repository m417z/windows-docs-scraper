# D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE structure

## Description

Specifies the (*x*, *y*, *z*) coordinate values below the index tiles of a tiled resource, along with the respective subresource. Note that the coordinate values do not indicate pixels or bytes.

## Members

### `X`

The *x* coordinate of the tiled resource. Used for buffer, 1-D, 2-D, and 3-D rendering.

### `Y`

The *y* coordinate of the tiled resource. Used for 2-D and 3-D rendering.

### `Z`

The *z* coordinate of the tiled resource. Used for 3-D rendering.

### `Subresource`

The subresource of the tiled resource. Used to index into mipmaps and arrays for 1-D, 2-D, and 3-D rendering.

If mipmaps are packed into a single tile, any subresource value that indicates any of the packed mipmaps refers to the same tile.