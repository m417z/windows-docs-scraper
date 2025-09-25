# IXpsOMObjectFactory::CreateImageBrush

## Description

Creates an [IXpsOMImageBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimagebrush) interface.

## Parameters

### `image` [in]

The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the image to be used as the source image of the brush.

### `viewBox` [in]

The [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that defines the *viewbox*, which is the area of the source image that is used by the brush.

### `viewPort` [in]

The [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that defines the *viewport*, which is the area covered by the first tile in the output area.

### `imageBrush` [out, retval]

A pointer to the new [IXpsOMImageBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimagebrush) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *image*, *viewBox*, *viewPort*, or *imageBrush* is **NULL**. |
| **E_INVALIDARG** | *viewBox* or *viewPort* contains a rectangle or value that is not valid. |

## Remarks

The brush's viewbox specifies the portion of a source image or visual to be used as the tile image.

The coordinates of the brush's viewbox are relative to the source content, such that (0,0) specifies the upper-left corner of the source content. For images, dimensions specified by the brush's viewbox are expressed in the units of 1/96". The corresponding pixel coordinates in the source image are calculated as follows:

In the illustration that follows, the image on the left is an example of a source image, and that on the far right is the brush that results after selecting the viewbox.

![An illustration that shows a viewbox example](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/CreateBrush.png)
If the source image resolution is 96 by 96 dots per inch and image dimensions are 96 by 96 pixels, the values of fields in the *viewbox* parameter are as follows:

The preceding parameter values correspond to the source image as follows:

SourceLeft = (96 × 48) / 96 = 48 pixels from the left side

SourceTop = (96 × 24) / 96 = 24 pixels from the top

SourceWidth = (96 × 24) / 96 = 24 pixels wide

SourceHeight = (96 × 48) / 96 = 48 pixels high

An image brush is a tile brush that takes an image, or a part of it, transforms the image to create a tile, places the resulting tile in the viewport (the destination geometry of the tile in the output area), and fills the output area as described by the tile mode.

The *viewport* is the area covered by the first tile in the output area. The viewport image is repeated throughout the output area as described by the tile mode.

The next illustration shows how an image brush is used to fill an output area. From left to right, the original image is transformed to fill the viewport, then placed in the viewport area of the output area, and then tiled to fill the output area.

![A figure that shows how a tile brush fills a geometry](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/tile_cherry.png)
The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMImageBrush            *newInterface;
// The following values are defined outside of
// this example.
//  IXpsOMImageResource     *image;
//  XPS_RECT                viewBox;
//  XPS_RECT                viewPort;

// Note the implicit requirement that CoInitializeEx
//  has previously been called from this thread.

hr = CoCreateInstance(
    __uuidof(XpsOMObjectFactory),
    NULL,
    CLSCTX_INPROC_SERVER,
    _uuidof(IXpsOMObjectFactory),
    reinterpret_cast<LPVOID*>(&xpsFactory)
    );

if (SUCCEEDED(hr))
{
    hr = xpsFactory->CreateImageBrush (
        image,
        &viewBox,
        &viewPort,
        &newInterface);

    if (SUCCEEDED(hr))
    {
        // use newInterface

        newInterface->Release();
    }
    xpsFactory->Release();
}
else
{
    // evaluate HRESULT error returned in hr
}

```

## See also

[IXpsOMImageBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimagebrush)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect)