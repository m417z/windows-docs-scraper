# ICDrawStartPlay macro

## Description

The **ICDrawStartPlay** macro provides the start and end times of a play operation to a rendering driver. You can use this macro or explicitly call the [ICM_DRAW_START_PLAY](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-start-play) message.

## Parameters

### `hic`

Handle to a driver.

### `lFrom`

Start time.

### `lTo`

End time.

## Remarks

This message precedes any frame data sent to the rendering driver.

Units for *lFrom* and *lTo* are specified with the [ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin) message. For video data this is normally a frame number. For more information about the playback rate, see the **dwRate** and **dwScale** members of the [ICDRAWBEGIN](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-icdrawbegin) structure.

If the end time is less than the start time, the playback direction is reversed.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)