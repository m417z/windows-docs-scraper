# IXpsOMTileBrush::GetTileMode

## Description

Gets the [XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode) value that describes the tile mode of the brush.

## Parameters

### `tileMode` [out, retval]

The [XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode) value that describes the tile mode of the brush.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *tileMode* is **NULL**. |

## Remarks

The tile mode determines how the tile image is repeated to fill the output area. If the tile mode value is [XPS_TILE_MODE_NONE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode), the tile image is drawn only once. The following illustration shows examples of how the tile image appears in several tile modes.

![An illustration that shows different examples of different tile mode behaviors](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/TileMode.png)

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode)