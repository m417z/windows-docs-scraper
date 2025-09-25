# IWICPalette::HasAlpha

## Description

Indicates whether the palette contains an entry that is non-opaque (that is, an entry with an alpha that is less than 1).

## Parameters

### `pfHasAlpha` [out]

Type: **BOOL***

Pointer that receives `TRUE` if the palette contains a transparent color; otherwise, `FALSE`.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Various image formats support alpha in different ways. PNG has full alpha support by supporting partially transparent palette entries. GIF stores colors as 24bpp, without alpha, but allows one palette entry to be specified as fully transparent. If a palette has multiple fully transparent entries (0x00RRGGBB), GIF will use the last one as its transparent index.