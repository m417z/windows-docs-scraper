# IDWriteTextLayout::Draw

## Description

 Draws text using the specified client drawing context.

## Parameters

### `clientDrawingContext`

Type: **void***

An application-defined drawing context.

### `renderer`

Type: **[IDWriteTextRenderer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextrenderer)***

Pointer to the set of callback functions used to draw parts of a text string.

### `originX`

Type: **FLOAT**

The x-coordinate of the layout's left side.

### `originY`

Type: **FLOAT**

The y-coordinate of the layout's top side.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To draw text with this method, a *textLayout* object needs to be created by the application using [IDWriteFactory::CreateTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createtextlayout).

After the *textLayout* object is obtained, the application calls the **IDWriteTextLayout::Draw** method to draw the text, decorations, and inline objects. The actual drawing is done through the callback interface passed in as the *textRenderer* argument; there, the corresponding [DrawGlyphRun](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritebitmaprendertarget-drawglyphrun) API is called.

If you set a vertical text reading direction on IDWriteTextLayout via SetReadingDirection with DWRITE_READING_DIRECTION_TOP_TO_BOTTOM (or bottom to top), then you must pass an interface that implements IDWriteTextRenderer1. Otherwise you get the error DWRITE_E_TEXTRENDERERINCOMPATIBLE because the original IDWriteTextRenderer interface only supported horizontal text.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)