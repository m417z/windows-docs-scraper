# IDWriteGdiInterop::ConvertFontFaceToLOGFONT

## Description

 Initializes a LOGFONT structure based on the GDI-compatible properties of the specified font.

## Parameters

### `font`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)***

An [IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface) object to be converted into a GDI-compatible LOGFONT structure.

### `logFont` [out]

Type: **LOGFONTW***

When this method returns, contains a pointer to a structure that receives a GDI-compatible font description.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The conversion to a LOGFONT by using **ConvertFontFaceToLOGFONT** operates at the logical font level and does not guarantee that it will map to a specific physical font. It is not guaranteed that GDI will select the same physical font for displaying text formatted by a LOGFONT as the [IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont) object that was converted.

## See also

[IDWriteGdiInterop](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritegdiinterop)