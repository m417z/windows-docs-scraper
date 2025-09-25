# ICOPEN structure

## Description

The **ICOPEN** structure contains information about the data stream being compressed or decompressed, the version number of the driver, and how the driver is used.

## Members

### `dwSize`

Size, in bytes, of the structure.

### `fccType`

Four-character code indicating the type of stream being compressed or decompressed. Specify "VIDC" for video streams.

### `fccHandler`

Four-character code identifying a specific compressor.

### `dwVersion`

Version of the installable driver interface used to open the driver.

### `dwFlags`

Applicable flags indicating why the driver is opened. The following values are defined:

| Name | Description |
| --- | --- |
| **ICMODE_COMPRESS** | Driver is opened to compress data. |
| **ICMODE_DECOMPRESS** | Driver is opened to decompress data. |
| **ICMODE_DRAW** | Device driver is opened to decompress data directly to hardware. |
| **ICMODE_QUERY** | Driver is opened for informational purposes, rather than for compression. |

### `dwError`

### `pV1Reserved`

Reserved; do not use.

### `pV2Reserved`

Reserved; do not use.

### `dnDevNode`

Device node for plug and play devices.

## Remarks

This structure is passed to video capture drivers when they are opened. This allows a single installable driver to function as either an installable compressor or a video capture device. By examining the **fccType** member of the **ICOPEN** structure, the driver can determine its function. For example, a **fccType** value of "VIDC" indicates that it is opened as an installable video compressor.

## See also

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)