# IDWriteTextRenderer::DrawInlineObject

## Description

 IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw) calls this application callback when it needs to
draw an inline object.

## Parameters

### `clientDrawingContext`

Type: **void***

The application-defined drawing context passed to IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw).

### `originX`

Type: **FLOAT**

X-coordinate at the top-left corner of the inline object.

### `originY`

Type: **FLOAT**

Y-coordinate at the top-left corner of the inline object.

### `inlineObject`

Type: **[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)***

The application-defined inline object set using [IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)::[SetInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-setinlineobject).

### `isSideways`

Type: **BOOL**

A Boolean flag that indicates whether the object's baseline runs alongside the baseline axis of the line.

### `isRightToLeft`

Type: **BOOL**

A Boolean flag that indicates whether the object is in a right-to-left context, hinting that the drawing may want to mirror the normal image.

### `clientDrawingEffect`

Type: **IUnknown***

Application-defined drawing effects for the glyphs to render. Usually this argument represents effects such as the foreground brush filling the interior of a line.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextRenderer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextrenderer)