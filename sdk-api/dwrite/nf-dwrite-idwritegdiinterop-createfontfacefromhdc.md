# IDWriteGdiInterop::CreateFontFaceFromHdc

## Description

 Creates an **IDWriteFontFace** object that corresponds to the currently selected **HFONT** of the specified **HDC**.

## Parameters

### `hdc`

Type: **HDC**

A handle to a device context into which a font has been selected. It is assumed that the client
has already performed font mapping and that the font selected into the device context is the actual font to be used
for rendering glyphs.

### `fontFace` [out]

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)****

Contains an address of a pointer to the newly created font face object, or **NULL** in case of failure. The font face returned is guaranteed to reference the same physical typeface that would be used for drawing glyphs (but not necessarily characters) using ExtTextOut.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is intended for scenarios in which an application wants to use GDI and Uniscribe 1.x for text layout and shaping, but DirectWrite for final rendering. This function assumes the client is performing text output using glyph indexes.

## See also

[IDWriteGdiInterop](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritegdiinterop)