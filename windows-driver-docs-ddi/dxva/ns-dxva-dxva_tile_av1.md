## Description

The **DXVA_Tile_AV1** structure is sent by the host software decoder to the accelerator to convey tile data locations.

## Members

### `DataOffset`

Locates the compressed bitstream data for the current tile. Specifically, **DataOffset** is the byte offset from the start of the bitstream buffer of either tile_list_obu, codec_tile_data or tile_group_obu, init_symbol(tileSize) from the AV1 specification.

### `DataSize`

Number of bytes in the bitstream data buffer that are associated with this tile or list of tiles starting at the byte given by **DataOffset**.

### `row`

The row that this tile belongs to. When part of a Tile List Open Bitstream Unit (OBU), this specifies the anchor_tile_row from the AV1 specification.

### `column`

The column that this tile belongs to. When part of a Tile List OBU, this specifies the anchor_tile_column from the AV1 specification.

### `Reserved16Bits`

Reserved; set to 0. The accelerator ignores this field.

### `anchor_frame`

Specifies an associated anchor_frame for the tile list OBU. This is to be translated to the source frame buffer/surface index for the reference tile picture, from the anchor_frame_idx value in the specification. If this tile is not part of a Tile List OBU then this frame will have the standard invalid frame index of 255.

### `Reserved8Bits`

Reserved; set to 0. The accelerator ignores this field.

## Remarks

See the [Direct X Video Acceleration Specification for AV1 Video Coding](https://www.microsoft.com/download/details.aspx?id=101577) for detailed information, including how to use this structure.