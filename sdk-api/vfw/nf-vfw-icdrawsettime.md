# ICDrawSetTime macro

## Syntax

```cpp
DWORD ICDrawSetTime(
     hic,
     lTime
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDrawSetTime** macro provides synchronization information to a rendering driver that handles the timing of drawing frames. The synchronization information is the sample number of the frame to draw. You can use this macro or explicitly call the [ICM_DRAW_SETTIME](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-settime) message.

## Parameters

### `hic`

Handle to a driver.

### `lTime`

Sample number of the frame to render.

## Remarks

Typically, the driver compares the specified value with the frame number associated with the time of its internal clock and attempts to synchronize the two if the difference is significant.

Use this message when the hardware performs its own asynchronous decompression, timing, and drawing, and the hardware relies on an external synchronization signal (the hardware is not being used as the synchronization master).

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)