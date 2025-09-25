# D3DWDDM1_3DDI_TILE_MAPPING_FLAG enumeration

## Description

Indicates how to update a tile mapping.

## Constants

### `D3DWDDM1_3DDI_TILE_MAPPING_NO_OVERWRITE`

Previously submitted commands to the
device that may still be executing do not reference any of the tile region being updated.
This allows the device to avoid having to flush previously submitted work in order to update a tile mapping.