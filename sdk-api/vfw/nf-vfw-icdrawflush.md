# ICDrawFlush macro

## Syntax

```cpp
DWORD ICDrawFlush(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDrawFlush** macro notifies a rendering driver to render the contents of any image buffers that are waiting to be drawn. You can use this macro or explicitly call the [ICM_DRAW_FLUSH](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-flush) message.

## Parameters

### `hic`

Handle to a driver.

## Remarks

This message is used only by hardware that performs its own asynchronous decompression, timing, and drawing.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)