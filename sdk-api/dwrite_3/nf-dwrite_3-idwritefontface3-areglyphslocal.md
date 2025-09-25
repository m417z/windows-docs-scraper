# IDWriteFontFace3::AreGlyphsLocal

## Description

Determines whether the specified glyphs are local.

## Parameters

### `glyphIndices` [in]

Type: **UINT16**

Array of glyph indices.

### `glyphCount`

Type: **UINT32**

The number of elements in the glyph index array.

### `enqueueIfNotLocal`

Type: **BOOL**

Specifies whether to enqueue a download request
if any of the specified glyphs are not local.

### `isLocal` [out]

Type: **BOOL***

Receives TRUE if all of the specified glyphs are local,
FALSE if any of the specified glyphs are remote.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)