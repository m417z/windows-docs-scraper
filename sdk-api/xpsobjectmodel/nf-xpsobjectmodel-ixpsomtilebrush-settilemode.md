# IXpsOMTileBrush::SetTileMode

## Description

Sets the [XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode) value that describes the tiling mode of the brush.

## Parameters

### `tileMode` [in]

The [XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode) value to be set.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *tileMode* was not a valid [XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode) value. |

## Remarks

The tile mode determines how the tile image is repeated to fill the output area. If the tile mode value is [XPS_TILE_MODE_NONE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode), the tile image is drawn only once.

![An illustration that shows different examples of different tile mode behaviors](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/TileMode.png)

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_TILE_MODE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_tile_mode)