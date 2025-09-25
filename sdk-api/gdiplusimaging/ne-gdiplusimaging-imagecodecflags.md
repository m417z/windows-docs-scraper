# ImageCodecFlags enumeration

## Description

The **ImageCodecFlags** enumeration indicates attributes of an image codec.

## Constants

### `ImageCodecFlagsEncoder:0x00000001`

Indicates that the codec supports encoding (saving).

### `ImageCodecFlagsDecoder:0x00000002`

Indicates that the codec supports decoding (reading).

### `ImageCodecFlagsSupportBitmap:0x00000004`

Indicates that the codec supports raster images (bitmaps).

### `ImageCodecFlagsSupportVector:0x00000008`

Indicates that the codec supports vector images (metafiles).

### `ImageCodecFlagsSeekableEncode:0x00000010`

Indicates that an encoder requires a seekable output stream.

### `ImageCodecFlagsBlockingDecode:0x00000020`

Indicates that a decoder has blocking behavior during the decoding process.

### `ImageCodecFlagsBuiltin:0x00010000`

Indicates that the codec is built in to GDI+.

### `ImageCodecFlagsSystem:0x00020000`

Not used in GDI+ version 1.0.

### `ImageCodecFlagsUser:0x00040000`

Not used in GDI+ version 1.0.