# ICCOMPRESS structure

## Description

The **ICCOMPRESS** structure contains compression parameters used with the [ICM_COMPRESS](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress) message.

## Members

### `dwFlags`

Flags used for compression. The following value is defined:

| Name | Description |
| --- | --- |
| **ICCOMPRESS_KEYFRAME** | Input data should be treated as a key frame. |

### `lpbiOutput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output (compressed) format. The **biSizeImage** member must contain the size of the compressed data.

### `lpOutput`

Pointer to the buffer where the driver should write the compressed data.

### `lpbiInput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input (uncompressed) format.

### `lpInput`

Pointer to the buffer containing input data.

### `lpckid`

Address to contain the chunk identifier for data in the AVI file. If the value of this member is not **NULL**, the driver should specify a two-character code for the chunk identifier corresponding to the chunk identifier used in the AVI file.

### `lpdwFlags`

Address to contain flags for the AVI index. If the returned frame is a key frame, the driver should set the **AVIIF_KEYFRAME** flag.

### `lFrameNum`

Number of the frame to compress.

### `dwFrameSize`

Desired maximum size, in bytes, for compressing this frame. The size value is used for compression methods that can make tradeoffs between compressed image size and image quality. Specify zero for this member to use the default setting.

### `dwQuality`

Quality setting.

### `lpbiPrev`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the format of the previous frame, which is typically the same as the input format.

### `lpPrev`

Pointer to the buffer containing input data of the previous frame.

## Remarks

Drivers that perform temporal compression use data from the previous frame (found in the **lpbiPrev** and **lpPrev** members) to prune redundant data from the current frame.

## See also

[ICM_COMPRESS](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)