# IDWriteGlyphRunAnalysis::CreateAlphaTexture

## Description

 Creates an alpha texture of the specified type for glyphs within a specified bounding rectangle.

## Parameters

### `textureType`

Type: **[DWRITE_TEXTURE_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_texture_type)**

A value that specifies the type of texture requested. This can be [DWRITE_TEXTURE_BILEVEL_1x1](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_texture_type) or **DWRITE_TEXTURE_CLEARTYPE_3x1**. If a bi-level texture is requested, the
texture contains only bi-level glyphs. Otherwise, the texture contains only antialiased glyphs.

### `textureBounds` [in]

Type: **const RECT***

The bounding rectangle of the texture, which can be different than
the bounding rectangle returned by [GetAlphaTextureBounds](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteglyphrunanalysis-getalphatexturebounds).

### `alphaValues` [out]

Type: **BYTE***

When this method returns, contains the array of alpha values from the texture. The buffer allocated for this array must be at least the size of *bufferSize*.

### `bufferSize`

Type: **UINT32**

The size of the *alphaValues* array, in bytes. The minimum size depends on the dimensions of the
rectangle and the type of texture requested.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis)