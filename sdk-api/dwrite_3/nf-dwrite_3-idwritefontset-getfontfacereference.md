# IDWriteFontSet::GetFontFaceReference

## Description

Gets a reference to the font at the specified index, which may be local or remote.

## Parameters

### `listIndex`

Type: **UINT32**

Zero-based index of the font.

### `fontFaceReference` [out]

Type: **[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)****

Receives a pointer the font face reference object, or nullptr on failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)