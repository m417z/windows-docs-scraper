# ICDrawStop macro

## Description

The **ICDrawStop** macro notifies a rendering driver to stop its internal clock for the timing of drawing frames. You can use this macro or explicitly call the [ICM_DRAW_STOP](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-stop) message.

## Parameters

### `hic`

Handle to a driver.

## Remarks

This macro is used by hardware that performs its own asynchronous decompression, timing, and drawing.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)