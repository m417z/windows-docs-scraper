# IDWriteBitmapRenderTarget::DrawGlyphRun

## Description

 Draws a run of glyphs to a bitmap target at the specified position.

## Parameters

### `baselineOriginX`

Type: **FLOAT**

The horizontal position of the baseline origin, in DIPs, relative to the upper-left corner of the DIB.

### `baselineOriginY`

Type: **FLOAT**

The vertical position of the baseline origin, in DIPs, relative to the upper-left corner of the DIB.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring method for glyphs in the run, used with the other properties to determine the rendering mode.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)***

The structure containing the properties of the glyph run.

### `renderingParams`

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)***

The object that controls rendering behavior.

### `textColor`

Type: **COLORREF**

The foreground color of the text.

### `blackBoxRect` [out, optional]

Type: **RECT***

The optional rectangle that receives the bounding box (in pixels not DIPs) of all the pixels affected by
drawing the glyph run. The black box rectangle may extend beyond the dimensions of the bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the **IDWriteBitmapRenderTarget::DrawGlyphRun** to render to a bitmap from a custom text renderer that you implement. The custom text renderer should call this method from within the [IDWriteTextRenderer::DrawGlyphRun](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextrenderer-drawglyphrun) callback method as shown in the following code.

```cpp
STDMETHODIMP GdiTextRenderer::DrawGlyphRun(
    __maybenull void* clientDrawingContext,
    FLOAT baselineOriginX,
    FLOAT baselineOriginY,
    DWRITE_MEASURING_MODE measuringMode,
    __in DWRITE_GLYPH_RUN const* glyphRun,
    __in DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription,
    IUnknown* clientDrawingEffect
    )
{
    HRESULT hr = S_OK;

    // Pass on the drawing call to the render target to do the real work.
    RECT dirtyRect = {0};

    hr = pRenderTarget_->DrawGlyphRun(
        baselineOriginX,
        baselineOriginY,
        measuringMode,
        glyphRun,
        pRenderingParams_,
        RGB(0,200,255),
        &dirtyRect
        );

    return hr;
}

```

The *baselineOriginX*, *baslineOriginY*, *measuringMethod*, and *glyphRun* parameters are provided (as arguments) when the callback method is invoked. The *renderingParams*, *textColor* and *blackBoxRect* are not.

Default rendering params can be retrieved by using the [IDWriteFactory::CreateMonitorRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createmonitorrenderingparams) method.

## See also

[IDWriteBitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritebitmaprendertarget)