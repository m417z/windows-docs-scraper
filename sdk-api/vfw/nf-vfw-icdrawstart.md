# ICDrawStart macro

## Description

The **ICDrawStart** macro notifies a rendering driver to start its internal clock for the timing of drawing frames. You can use this macro or explicitly call the [ICM_DRAW_START](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-start) message.

## Parameters

### `hic`

Handle to a driver.

## Remarks

This message is used by hardware that performs its own asynchronous decompression, timing, and drawing.

When the driver receives this message, it should start rendering data at the rate specified with the [ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin) message.

The **ICDrawStart** and [ICDrawStop](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdrawstop) macros do not nest. If your driver receives **ICDrawStart** before rendering is stopped with **ICDrawStop**, it should restart rendering with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)