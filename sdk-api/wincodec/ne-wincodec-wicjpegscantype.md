# WICJpegScanType enumeration

## Description

Specifies the memory layout of pixel data in a JPEG image scan.

## Constants

### `WICJpegScanTypeInterleaved:0`

The pixel data is stored in an interleaved memory layout.

### `WICJpegScanTypePlanarComponents:0x1`

The pixel data is stored in a planar memory layout.

### `WICJpegScanTypeProgressive:0x2`

The pixel data is stored in a progressive layout.

### `WICJpegScanType_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## See also

[WICJpegScanType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicjpegscantype)