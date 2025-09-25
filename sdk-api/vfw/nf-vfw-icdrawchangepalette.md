# ICDrawChangePalette macro

## Syntax

```cpp
DWORD ICDrawChangePalette(
     hic,
     lpbiInput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or **FALSE** otherwise.

## Description

The **ICDrawChangePalette** macro notifies a rendering driver that the movie palette is changing. You can use this macro or explicitly call the [ICM_DRAW_CHANGEPALETTE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-changepalette) message.

## Parameters

### `hic`

Handle to a rendering driver.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the new format and optional color table.

## Remarks

This message should be supported by installable rendering handlers that draw DIBs with an internal structure that includes a palette.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)