# ICDrawQuery macro

## Syntax

```cpp
DWORD ICDrawQuery(
     hic,
     lpbiInput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the driver can render data in the specified format or ICERR_BADFORMAT otherwise.

## Description

The **ICDrawQuery** macro queries a rendering driver to determine if it can render data in a specific format. You can use this macro or explicitly call the [ICM_DRAW_QUERY](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-query) message.

## Parameters

### `hic`

Handle to a driver.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input format.

## Remarks

This macro differs from the [ICDrawBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdrawbegin) macro in that it queries the driver in a general sense. **ICDrawBegin** determines if the driver can draw the data using the specified format under specific conditions, such as stretching the image.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)