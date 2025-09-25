## Description

Defines constants that specify High Efficiency Image Format (HEIF) compression options. Allows you to choose which compression format to use when creating a HEIF image file.

## Constants

### `WICHeifCompressionDontCare:0x0`

Specifies that any compression option may be used.

### `WICHeifCompressionNone:0x1`

Specifies that no compression be used.

### `WICHeifCompressionHEVC:0x2`

Specifies that High Efficiency Video Coding (HEVC) compression be used.

### `WICHeifCompressionAV1:0x3`

Specifies that AOMedia Video 1 (AV1) compression be used.

### `WICHeifCompressionJpegXL:0x4`

Specifies that JPEG XL should be used as the image compression format inside the HEIF file. Since JPEG XL supports both lossy and lossless compression, the *Lossless* compression option must also be set to **VARIANT_TRUE** to enable lossless encoding using JPEG XL. The *CompressionQuality* compression option is also available when using JPEG XL. *CompressionQuality* is a floating point number between 0 and 1, and the default value is 0.45. Larger values result in a smaller image size, at the expense of longer encoding time.

### `WICHeifCompressionBrotli:0x5`

Specifies that the Brotli lossless compression algorithm will be applied to the pixels. Brotli is defined in RFC 7932. Brotli generally provides a higher compression ratio than **WICHeifCompressionDeflate**, at the expense of being slower.

### `WICHeifCompressionDeflate:0x6`

Specifies that the Deflate lossless compression algorithm will be applied to the pixels. Defalate is defined in RFC 1951. Deflate is generally *faster* than Brotli (so it's more efficient), but it doesn't compress as well (so it's less effective).

### `WICHEIFCOMPRESSIONOPTION_FORCE_DWORD`

## Remarks

## See also