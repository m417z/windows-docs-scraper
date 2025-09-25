# IXpsOMTileBrush::GetViewport

## Description

Gets the portion of the destination geometry that is covered by a single tile.

## Parameters

### `viewport` [out, retval]

The [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that describes the portion of the destination geometry that is covered by a single tile.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *viewport* is **NULL**. |

## Remarks

The viewport is the portion of the output area where the first tile is drawn. In the illustration, the viewport is outlined by the purple rectangle inside the red, dotted rectangle. The tile mode of the brush determines how the rest of the tiles are drawn in the output area.

![An image that shows how a viewport is mapped to the output area](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/viewport_image.png)

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)