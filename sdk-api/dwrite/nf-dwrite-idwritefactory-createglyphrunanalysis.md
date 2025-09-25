# IDWriteFactory::CreateGlyphRunAnalysis

## Description

 Creates a glyph run analysis object, which encapsulates information
used to render a glyph run.

## Parameters

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)***

A structure that contains the properties of the glyph run (font face, advances, and so on).

### `pixelsPerDip`

Type: **FLOAT**

Number of physical pixels per DIP (device independent pixel). For example, if rendering onto a 96 DPI bitmap then *pixelsPerDip* is 1. If rendering onto a 120 DPI bitmap then *pixelsPerDip* is 1.25.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

Optional transform applied to the glyphs and their positions. This transform is applied after the scaling specified the *emSize* and *pixelsPerDip*.

### `renderingMode`

Type: **[DWRITE_RENDERING_MODE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_rendering_mode)**

A value that specifies the rendering mode, which must be one of the raster rendering modes (that is, not default
and not outline).

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

Specifies the measuring mode to use with glyphs.

### `baselineOriginX`

Type: **FLOAT**

The horizontal position (X-coordinate) of the baseline origin, in DIPs.

### `baselineOriginY`

Type: **FLOAT**

Vertical position (Y-coordinate) of the baseline origin, in DIPs.

### `glyphRunAnalysis` [out]

Type: **[IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis)****

When this method returns, contains an address of a pointer to the newly created glyph run analysis object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The glyph run analysis object contains the results of analyzing the glyph run, including the positions of all the glyphs and references to all of the rasterized glyphs in the font cache.

#### Examples

The following code example shows how to create a glyph run analysis object. In this example, an empty glyph run is being used.

```cpp
HRESULT CreateGlyphRunAnalysis(IDWriteFontFace *pFontFace, IDWriteGlyphRunAnalysis **ppGlyphRunAnalysis)
{
    HRESULT hr = S_OK;
    IDWriteFactory* pDWriteFactory = NULL;

    // Create the DirectWrite factory.
    hr = DWriteCreateFactory(
            DWRITE_FACTORY_TYPE_SHARED,
            __uuidof(IDWriteFactory),
            reinterpret_cast<IUnknown**>(&pDWriteFactory)
            );

    DWRITE_GLYPH_RUN emptyGlyphRun = { 0 };
    UINT16 glyphIndex = 0;

    emptyGlyphRun.fontFace = pFontFace;
    emptyGlyphRun.glyphIndices = &glyphIndex;
    emptyGlyphRun.glyphCount = 0;

    emptyGlyphRun.fontEmSize = 12;

    IDWriteGlyphRunAnalysis* pGlyphRunAnalysis = NULL;

    if (SUCCEEDED(hr))
    {
        hr = pDWriteFactory->CreateGlyphRunAnalysis(
            &emptyGlyphRun,
            1.0f, // pixelsPerDip,
            NULL, // transform,
            DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC,
            DWRITE_MEASURING_MODE_GDI_CLASSIC,
            0.0f, // baselineOriginX,
            0.0f, // baselineOriginY,
            &pGlyphRunAnalysis);
    }

    *ppGlyphRunAnalysis = pGlyphRunAnalysis;

    SafeRelease(&pDWriteFactory);

    return S_OK;
}

```

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)