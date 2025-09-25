# IXpsOMTileBrush::SetViewbox

## Description

Sets the portion of the source content to be used as the tile image.

## Parameters

### `viewbox` [in]

An [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that describes the portion of the source content to be used as the tile image.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *viewbox* is **NULL**. |
| **E_INVALIDARG** | The rectangle described in *viewbox* was not valid. |

## Remarks

The brush's viewbox specifies the portion of a source image or visual to be used as the tile image.

The coordinates of the brush's viewbox are relative to the source content, such that (0,0) specifies the upper-left corner of the source content. For images, dimensions specified by the brush's viewbox are expressed in the units of 1/96". The corresponding pixel coordinates in the source image are calculated as follows:

In the illustration that follows, the image on the left is an example of a source image, while that on the right is the source image with the selected viewbox for the brush shown as a red rectangle. In this example, the part of the source image that is used as the content for the tile brush is the area within the red rectangle. The shaded area of the image is not used by the brush.

![An image that shows how a viewbox is mapped to a source image](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/viewbox_image.png)
If the source image resolution is 96 by 96 dots per inch and image dimensions are 96 by 96 pixels, the values of fields in the *viewbox* parameter would be:

The preceding parameter values correspond to the source image as:

SourceLeft = 96 * 48 / 96 = 48 pixels from the left side

SourceTop = 96 * 24 / 96 = 24 pixels from the top

SourceWidth = 96 * 24 / 96 = 24 pixels wide

SourceHeight = 96 * 48 / 96 = 48 pixels high

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)