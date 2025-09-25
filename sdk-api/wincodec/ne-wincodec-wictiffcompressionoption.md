# WICTiffCompressionOption enumeration

## Description

Specifies the Tagged Image File Format (TIFF) compression options.

## Constants

### `WICTiffCompressionDontCare:0`

Indicates a suitable compression algorithm based on the image and pixel format.

### `WICTiffCompressionNone:0x1`

Indicates no compression.

### `WICTiffCompressionCCITT3:0x2`

Indicates a CCITT3 compression algorithm. This algorithm is only valid for 1bpp pixel formats.

### `WICTiffCompressionCCITT4:0x3`

Indicates a CCITT4 compression algorithm. This algorithm is only valid for 1bpp pixel formats.

### `WICTiffCompressionLZW:0x4`

Indicates a LZW compression algorithm.

### `WICTiffCompressionRLE:0x5`

Indicates a RLE compression algorithm. This algorithm is only valid for 1bpp pixel formats.

### `WICTiffCompressionZIP:0x6`

Indicates a ZIP compression algorithm.

### `WICTiffCompressionLZWHDifferencing:0x7`

Indicates an LZWH differencing algorithm.

### `WICTIFFCOMPRESSIONOPTION_FORCE_DWORD:0x7fffffff`