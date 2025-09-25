# ID2D1CommandSink::Clear

## Description

Clears the drawing area to the specified color.

## Parameters

### `color` [in, optional]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)***

The color to which the command sink should be cleared.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The clear color is restricted by the currently selected clip and layer bounds.

If no color is specified, the color should be interpreted by context. Examples include but are not limited to:

* Transparent black for a premultiplied bitmap target.
* Opaque black for an ignore bitmap target.
* Containing no content (or white) for a printer page.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::Clear](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1rendertarget-clear)