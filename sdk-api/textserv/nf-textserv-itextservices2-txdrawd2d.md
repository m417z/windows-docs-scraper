# ITextServices2::TxDrawD2D

## Description

Draws the text services object by using Direct2D rendering.

## Parameters

### `pRenderTarget`

Type: **[ID2D1RenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1rendertarget)***

The Direct2D rendering object that draws the text services object.

### `lprcBounds`

Type: **[LPCRECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)**

The bounding (client) rectangle.

### `lprcUpdate`

Type: **[LPRECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The rectangle to update inside *lprcBounds* rectangle, in the logical coordinate system of drawing device context. If this parameter is NULL, the entire client rectangle should be drawn.

### `lViewId`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The view to draw.

| Value | Meaning |
| --- | --- |
| **TXTVIEW_ACTIVE** | Draw the in-place active view. |
| **TXTVIEW_INACTIVE** | Draw a view other than the in-place active view, for example, a print preview. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextServices2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices2)