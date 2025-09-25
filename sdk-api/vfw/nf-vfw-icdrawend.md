# ICDrawEnd macro

## Syntax

```cpp
DWORD ICDrawEnd(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDrawEnd** macro notifies a rendering driver to decompress the current image to the screen and to release resources allocated for decompression and drawing. You can use this macro or explicitly call the [ICM_DRAW_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-end) message.

## Parameters

### `hic`

Handle to a driver.

## Remarks

The [ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin) and [ICM_DRAW_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-end) messages do not nest. If your driver receives **ICM_DRAW_BEGIN** before decompression is stopped with **ICM_DRAW_END**, it should restart decompression with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)