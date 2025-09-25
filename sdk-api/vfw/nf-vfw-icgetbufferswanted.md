# ICGetBuffersWanted macro

## Syntax

```cpp
DWORD ICGetBuffersWanted(
     hic,
     lpdwBuffers
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or ICERR_UNSUPPORTED otherwise.

## Description

The **ICGetBuffersWanted** macro queries a driver for the number of buffers to allocate. You can use this macro or explicitly call the [ICM_GETBUFFERSWANTED](https://learn.microsoft.com/windows/desktop/Multimedia/icm-getbufferswanted) message.

## Parameters

### `hic`

Handle to a driver.

### `lpdwBuffers`

Address to contain the number of samples the driver needs to efficiently render the data.

## Remarks

This message is used by drivers that use hardware to render data and want to ensure a minimal time lag caused by waiting for buffers to arrive. For example, if a driver controls a video decompression board that can hold 10 frames of video, it could return 10 for this message. This instructs applications to try to stay 10 frames ahead of the frame it currently needs.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)