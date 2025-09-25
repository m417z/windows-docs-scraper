# IXpsOMThumbnailGenerator::GenerateThumbnail

## Description

Generates a thumbnail image of a page.

## Parameters

### `page` [in]

A pointer to the [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface that contains the page for which the thumbnail image will be created.

### `thumbnailType` [in]

The [XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type) value that specifies the type of thumbnail image to create.

### `thumbnailSize` [in]

The [XPS_THUMBNAIL_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_thumbnail_size) value that specifies the image size of the thumbnail to create.

### `imageResourcePartName` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the new thumbnail image part.

### `imageResource` [out, retval]

A pointer to the new [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the thumbnail image created by this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *page*, *imageResourcePartName*, or *imageResource* is **NULL**. |
| **E_INVALIDARG** | One of the following parameters contains a value that is not valid:<br><br>* *thumbnailType*: The image type must be PNG ([XPS_IMAGE_TYPE_PNG](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type)) or JPEG (**XPS_IMAGE_TYPE_JPEG**)<br>* *thumbnailSize*: *thumbnailSize* must be a member of [XPS_THUMBNAIL_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_thumbnail_size) |

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMThumbnailGenerator](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomthumbnailgenerator)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type)

[XPS_THUMBNAIL_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_thumbnail_size)