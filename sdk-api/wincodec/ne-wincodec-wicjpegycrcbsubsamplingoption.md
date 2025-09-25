# WICJpegYCrCbSubsamplingOption enumeration

## Description

Specifies the JPEG YCrCB subsampling options.

## Constants

### `WICJpegYCrCbSubsamplingDefault:0`

The default subsampling option.

### `WICJpegYCrCbSubsampling420:0x1`

Subsampling option that uses both horizontal and vertical decimation.

### `WICJpegYCrCbSubsampling422:0x2`

Subsampling option that uses horizontal decimation .

### `WICJpegYCrCbSubsampling444:0x3`

Subsampling option that uses no decimation.

### `WICJpegYCrCbSubsampling440:0x4`

Subsampling option that uses 2x vertical downsampling only. This option is only available in Windows 8.1 and later.

### `WICJPEGYCRCBSUBSAMPLING_FORCE_DWORD:0x7fffffff`

## Remarks

The native JPEG encoder uses **WICJpegYCrCbSubsampling420**.