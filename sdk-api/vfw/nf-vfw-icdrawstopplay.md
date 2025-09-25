# ICDrawStopPlay macro

## Description

The **ICDrawStopPlay** macro notifies a rendering driver when a play operation is complete. You can use this macro or explicitly call the [ICM_DRAW_STOP_PLAY](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-stop-play) message.

## Parameters

### `hic`

Handle to a driver.

## Remarks

Use this message when the play operation is complete. Use the [ICDrawStop](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdrawstop) macro to end timing.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)