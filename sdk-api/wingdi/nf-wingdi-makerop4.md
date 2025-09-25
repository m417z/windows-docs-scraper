# MAKEROP4 macro

## Syntax

```cpp
DWORD MAKEROP4(
    DWORD fore,
    DWORD back
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is a quaternary raster operation code for use with the [MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt) function.

## Description

The **MAKEROP4** macro creates a quaternary raster operation code for use with the [MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt) function. The macro takes two ternary raster operation codes as input, one for the foreground and one for the background, and packs their Boolean operation indexes into the high-order word of a 32-bit value. The low-order word of this value will be ignored.

## Parameters

### `fore`

The foreground ternary raster operation code.

### `back`

The background ternary raster operation code.

## See also

[Bitmap Macros](https://learn.microsoft.com/windows/desktop/gdi/bitmap-macros)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt)