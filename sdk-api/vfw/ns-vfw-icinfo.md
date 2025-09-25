# ICINFO structure

## Description

The **ICINFO** structure contains compression parameters supplied by a video compression driver. The driver fills or updates the structure when it receives the [ICM_GETINFO](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getinfo) message.

## Members

### `dwSize`

Size, in bytes, of the **ICINFO** structure.

### `fccType`

Four-character code indicating the type of stream being compressed or decompressed. Specify "VIDC" for video streams.

### `fccHandler`

A four-character code identifying a specific compressor.

### `dwFlags`

Applicable flags. Zero or more of the following flags can be set:

| Name | Description |
| --- | --- |
| **VIDCF_COMPRESSFRAMES** | Driver is requesting to compress all frames. For information about compressing all frames, see the [ICM_COMPRESS_FRAMES_INFO](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-frames-info) message. |
| **VIDCF_CRUNCH** | Driver supports compressing to a frame size. |
| **VIDCF_DRAW** | Driver supports drawing. |
| **VIDCF_FASTTEMPORALC** | Driver can perform temporal compression and maintains its own copy of the current frame. When compressing a stream of frame data, the driver doesn't need image data from the previous frame. |
| **VIDCF_FASTTEMPORALD** | Driver can perform temporal decompression and maintains its own copy of the current frame. When decompressing a stream of frame data, the driver doesn't need image data from the previous frame. |
| **VIDCF_QUALITY** | Driver supports quality values. |
| **VIDCF_TEMPORAL** | Driver supports inter-frame compression. |

### `dwVersion`

Version number of the driver.

### `dwVersionICM`

Version of VCM supported by the driver. This member should be set to ICVERSION.

### `szName`

Short version of the compressor name. The name in the null-terminated string should be suitable for use in list boxes.

### `szDescription`

Long version of the compressor name.

### `szDriver`

Name of the module containing VCM compression driver. Normally, a driver does not need to fill this out.

## See also

[ICM_COMPRESS_FRAMES_INFO](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-frames-info)

[ICM_GETINFO](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getinfo)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)