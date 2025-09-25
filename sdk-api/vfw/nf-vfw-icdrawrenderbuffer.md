# ICDrawRenderBuffer macro

## Description

The **ICDrawRenderBuffer** macro notifies a rendering driver to draw the frames that have been passed to it. You can use this macro or explicitly call the [ICM_DRAW_RENDERBUFFER](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-renderbuffer) message.

## Parameters

### `hic`

Handle to a driver.

## Remarks

Use this message with hardware that performs its own asynchronous decompression, timing, and drawing.

This message is typically used to perform a seek operation when the driver must be specifically instructed to display each video frame passed to it rather than playing a sequence of video frames.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)