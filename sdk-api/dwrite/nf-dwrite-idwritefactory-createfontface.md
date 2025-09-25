# IDWriteFactory::CreateFontFace

## Description

 Creates an object that represents a font face.

## Parameters

### `fontFaceType`

Type: **[DWRITE_FONT_FACE_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_face_type)**

A value that indicates the type of file format of the font face.

### `numberOfFiles`

Type: **UINT32**

The number of font files, in element count, required to represent the font face.

### `fontFiles` [in]

Type: **const [IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)***

A font file object representing the font face. Because [IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface) maintains its own references
to the input font file objects, you may release them after this call.

### `faceIndex`

Type: **UINT32**

The zero-based index of a font face, in cases when the font files contain a collection of font faces.
If the font files contain a single face, this value should be zero.

### `fontFaceSimulationFlags`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

A value that indicates which, if any, font face simulation flags for algorithmic means of making text bold or italic are applied to the current font face.

### `fontFace` [out]

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)****

When this method returns, contains an address of a pointer to the newly created font face object, or **NULL** in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)