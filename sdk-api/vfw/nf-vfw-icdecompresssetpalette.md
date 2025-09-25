# ICDecompressSetPalette macro

## Syntax

```cpp
DWORD ICDecompressSetPalette(
     hic,
     lpbiPalette
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the decompression driver can precisely decompress images to the suggested palette using the set of colors as they are arranged in the palette. Returns ICERR_UNSUPPORTED otherwise.

## Description

The **ICDecompressSetPalette** macro specifies a palette for a video decompression driver to use if it is decompressing to a format that uses a palette. You can use this macro or explicitly call the [ICM_DECOMPRESS_SET_PALETTE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-set-palette) message.

## Parameters

### `hic`

Handle to a decompressor.

### `lpbiPalette`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure whose color table contains the colors that should be used if possible. You can specify zero to use the default set of output colors.

## Remarks

This macro should not affect decompression already in progress; rather, colors passed using this message should be returned in response to future [ICDecompressGetFormat](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressgetformat) and [ICDecompressGetPalette](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressgetpalette) macros. Colors are sent back to the decompression driver in a future ICDecompressBegin macro.

This macro is used primarily when a driver decompresses images to the screen and another application that uses a palette is in the foreground, forcing the decompression driver to adapt to a foreign set of colors.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)