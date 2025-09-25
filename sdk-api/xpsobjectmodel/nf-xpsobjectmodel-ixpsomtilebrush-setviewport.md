# IXpsOMTileBrush::SetViewport

## Description

Sets the portion of the destination geometry that is covered by a single tile.

## Parameters

### `viewport` [in]

An [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that describes the portion of the destination geometry that is covered by a single tile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *viewport* is **NULL**. |
| **E_INVALIDARG** | The rectangle described in *viewport* is not valid. |

## Remarks

The viewport is the portion of the output area where the tile is drawn. In the following illustration, the viewport is outlined by the blue rectangle inside the red, dotted rectangle. The tile mode of the brush determines how other tiles are drawn in the output area.

![An image that shows how a viewport is mapped to the output area](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/viewport_image.png)

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)