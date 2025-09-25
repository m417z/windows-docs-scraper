# ICDrawRealize macro

## Syntax

```cpp
DWORD ICDrawRealize(
     hic,
     hdc,
     fBackground
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the drawing palette is realized or ICERR_UNSUPPORTED if the palette associated with the decompressed data is realized.

## Description

The **ICDrawRealize** macro notifies a rendering driver to realize its drawing palette while drawing. You can use this macro or explicitly call the [ICM_DRAW_REALIZE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-realize) message.

## Parameters

### `hic`

Handle to a driver.

### `hdc`

Handle of the DC used to realize the palette.

### `fBackground`

Background flag. Specify **TRUE** to realize the palette as a background task or **FALSE** to realize the palette in the foreground.

## Remarks

Drivers need to respond to this message only if the drawing palette is different from the decompressed palette.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)