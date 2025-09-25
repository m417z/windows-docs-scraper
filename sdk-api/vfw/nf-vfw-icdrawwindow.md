# ICDrawWindow macro

## Syntax

```cpp
DWORD ICDrawWindow(
     hic,
     prc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDrawWindow** macro notifies a rendering driver that the window specified for the [ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin) message needs to be redrawn. The window has moved or become temporarily obscured. You can use this macro or explicitly call the [ICM_DRAW_WINDOW](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-window) message.

## Parameters

### `hic`

Handle to a driver.

### `prc`

Pointer to the destination rectangle in screen coordinates. If this parameter points to an empty rectangle, drawing should be turned off.

## Remarks

This message is supported by hardware that performs its own asynchronous decompression, timing, and drawing.

Video-overlay drivers use this message to draw when the window is obscured or moved. When a window specified for [ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin) is completely hidden by other windows, the destination rectangle is empty. Drivers should turn off video-overlay hardware when this condition occurs.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)