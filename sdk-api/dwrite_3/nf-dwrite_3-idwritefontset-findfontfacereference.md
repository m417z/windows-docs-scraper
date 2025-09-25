# IDWriteFontSet::FindFontFaceReference

## Description

Gets the index of the matching font face reference in the font set, with the same file, face index, and simulations.

## Parameters

### `fontFaceReference`

Type: **[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)***

Font face object that specifies the physical font.

### `listIndex` [out]

Type: **UINT32***

Receives the zero-based index of the matching font if the font was found, or UINT_MAX otherwise.

### `exists` [out]

Type: **BOOL***

Receives TRUE if the font exists or FALSE otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)