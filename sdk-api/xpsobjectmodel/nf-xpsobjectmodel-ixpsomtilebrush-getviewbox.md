# IXpsOMTileBrush::GetViewbox

## Description

Gets the portion of the source image to be used by the tile.

## Parameters

### `viewbox` [out, retval]

The [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that describes the area of the source content to be used by the tile.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *viewbox* is **NULL**. |

## Remarks

The brush's viewbox specifies the portion of a source image or visual to be used as the tile image.

The coordinates of the brush's viewbox are relative to the source content, such that (0,0) specifies the upper-left corner of the source content. For images, dimensions specified by the brush's viewbox are expressed in the units of 1/96". The corresponding pixel coordinates in the source image are calculated as follows:

In the illustration that follows, the image on the left is an example of a source image, the image in the center shows the selected viewbox, and the image on the right shows the resulting brush.

![An illustration that shows a viewbox example](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/CreateBrush.png)
If the source image resolution is 96 by 96 dots per inch and image dimensions are 96 by 96 pixels, the values of fields in the *viewbox* parameter would be:

The preceding parameter values correspond to the source image as:

SourceLeft = 96 × 48 / 96 = 48 pixels from the left side

SourceTop = 96 × 4 / 96 = 24 pixels from the top

SourceWidth = 96 × 24 / 96 = 24 pixels wide

SourceHeight = 96 × 48 / 96 = 48 pixels high

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)