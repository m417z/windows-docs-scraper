# ICDecompressGetPalette macro

## Syntax

```cpp
DWORD ICDecompressGetPalette(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDecompressGetPalette** macro requests that the video decompression driver supply the color table of the output [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure. You can use this macro or explicitly call the [ICM_DECOMPRESS_GET_PALETTE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-get-palette) message.

## Parameters

### `hic`

Handle to a decompressor.

### `lpbiInput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format.

### `lpbiOutput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure to contain the color table. The space reserved for the color table is always at least 256 colors. You can specify zero for this parameter to return only the size of the color table.

## Remarks

If *lpbiOutput* is nonzero, the driver sets the **biClrUsed** member of [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) to the number of colors in the color table. The driver fills the **bmiColors** members of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) with the actual colors.

The driver should support this message only if it uses a palette other than the one specified in the input format.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)