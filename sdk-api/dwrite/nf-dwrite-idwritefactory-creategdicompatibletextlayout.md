# IDWriteFactory::CreateGdiCompatibleTextLayout

## Description

 Takes a string, format, and associated constraints,
and produces an object representing the result, formatted for a particular display resolution
and measuring mode.

## Parameters

### `string` [in]

Type: **const WCHAR***

An array of characters that contains the string to create a new [IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) object from. This array must be of length *stringLength* and can contain embedded **NULL** characters.

### `stringLength`

Type: **UINT32**

The length of the string, in character count.

### `textFormat`

Type: **[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)***

The text formatting object to apply to the string.

### `layoutWidth`

Type: **FLOAT**

The width of the layout box.

### `layoutHeight`

Type: **FLOAT**

The height of the layout box.

### `pixelsPerDip`

Type: **FLOAT**

The number of physical pixels per DIP (device independent pixel). For example, if rendering onto a 96 DPI device *pixelsPerDip* is 1. If rendering onto a 120 DPI device *pixelsPerDip* is 1.25 (120/96).

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

An optional transform applied to the glyphs and their positions. This transform is applied after the
scaling specifies the font size and pixels per DIP.

### `useGdiNatural`

Type: **BOOL**

 Instructs the text layout to use the same metrics as GDI bi-level text when set to **FALSE**.
When set to **TRUE**, instructs the text layout to use the same metrics as text measured by GDI using a font
created with **CLEARTYPE_NATURAL_QUALITY**.

### `textLayout` [out]

Type: **[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)****

When this method returns, contains an address to the pointer of the resultant text layout object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The resulting text layout should only be used for the intended resolution,
and for cases where text scalability is desired [CreateTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createtextlayout) should be used instead.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)