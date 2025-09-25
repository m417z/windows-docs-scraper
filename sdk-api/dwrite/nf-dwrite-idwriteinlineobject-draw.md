# IDWriteInlineObject::Draw

## Description

 The application implemented rendering callback ([IDWriteTextRenderer::DrawInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextrenderer-drawinlineobject))
can use this to draw the inline object without needing to cast or query the object
type. The text layout does not call this method directly.

## Parameters

### `clientDrawingContext`

Type: **void***

The drawing context passed to [IDWriteTextLayout::Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-draw). This parameter may be **NULL**.

### `renderer`

Type: **[IDWriteTextRenderer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextrenderer)***

The same renderer passed to [IDWriteTextLayout::Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-draw) as the object's containing parent. This is useful if the inline object is recursive such as a nested layout.

### `originX`

Type: **FLOAT**

The x-coordinate at the upper-left corner of the inline object.

### `originY`

Type: **FLOAT**

The y-coordinate at the upper-left corner of the inline object.

### `isSideways`

Type: **BOOL**

A Boolean flag that indicates whether the object's baseline runs alongside the baseline axis of the line.

### `isRightToLeft`

Type: **BOOL**

A Boolean flag that indicates whether the object is in a right-to-left context and should be drawn flipped.

### `clientDrawingEffect`

Type: **IUnknown***

The drawing effect set in [IDWriteTextLayout::SetDrawingEffect](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-setdrawingeffect). Usually this effect is a foreground brush that is used in glyph drawing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)