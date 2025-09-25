# IDWriteFontFile::Analyze

## Description

 Analyzes a file and returns whether it represents a font, and whether the font type is supported by the font system.

## Parameters

### `isSupportedFontType` [out]

Type: **BOOL***

**TRUE** if the font type is supported by the font system; otherwise, **FALSE**.

### `fontFileType` [out]

Type: **[DWRITE_FONT_FILE_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_file_type)***

When this method returns, contains a value that indicates the type of the font file. Note that even if  *isSupportedFontType* is **FALSE**,
the *fontFileType* value may be different from **DWRITE_FONT_FILE_TYPE_UNKNOWN**.

### `fontFaceType` [out, optional]

Type: **[DWRITE_FONT_FACE_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_face_type)***

When this method returns, contains a value that indicates the type of the font face. If *fontFileType* is not equal to **DWRITE_FONT_FILE_TYPE_UNKNOWN**, then that can be constructed from the font file.

### `numberOfFaces` [out]

Type: **UINT32***

When this method returns, contains the number of font faces contained in the font file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Important** Certain font file types are recognized, but not supported by the font system.
For example, the font system will recognize a file as a Type 1 font file
but will not be able to construct a font face object from it. In such situations, **Analyze** will set
*isSupportedFontType* output parameter to **FALSE**.

## See also

[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)