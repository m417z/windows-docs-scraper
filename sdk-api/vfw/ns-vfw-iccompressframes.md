# ICCOMPRESSFRAMES structure

## Description

The **ICCOMPRESSFRAMES** structure contains compression parameters used with the [ICM_COMPRESS_FRAMES_INFO](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-frames-info) message.

## Members

### `dwFlags`

Applicable flags. The following value is defined: **ICCOMPRESSFRAMES_PADDING**. If this value is used, padding is used with the frame.

### `lpbiOutput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output format.

### `lOutput`

Reserved; do not use.

### `lpbiInput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format.

### `lInput`

Reserved; do not use.

### `lStartFrame`

Number of the first frame to compress.

### `lFrameCount`

Number of frames to compress.

### `lQuality`

Quality setting.

### `lDataRate`

Maximum data rate, in bytes per second.

### `lKeyRate`

Maximum number of frames between consecutive key frames.

### `dwRate`

Compression rate in an integer format. To obtain the rate in frames per second, divide this value by the value in **dwScale**.

### `dwScale`

Value used to scale **dwRate** to frames per second.

### `dwOverheadPerFrame`

Reserved; do not use.

### `dwReserved2`

Reserved; do not use.

### `GetData`

Reserved; do not use.

### `PutData`

Reserved; do not use.

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/previous-versions//ms532290(v=vs.85))

[ICM_COMPRESS_FRAMES_INFO](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-frames-info)

Video Compression Manager

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)