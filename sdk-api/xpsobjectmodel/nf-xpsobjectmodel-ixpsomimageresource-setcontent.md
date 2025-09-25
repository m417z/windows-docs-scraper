# IXpsOMImageResource::SetContent

## Description

Sets the read-only stream to be associated with this resource.

## Parameters

### `sourceStream` [in]

The read-only stream to be associated with this resource.

### `imageType` [in]

The [XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type) value that describes the type of image in the stream.

### `partName` [in]

The part name to be assigned to this resource.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The calling method should treat this stream as a single-threaded apartment (STA) model object and not re-enter any of the stream interface's methods.

Because [GetStream](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomimageresource-getstream) gets a clone of the stream that is set by this method, the provided stream should have an efficient cloning method. A stream with an inefficient cloning method will reduce the performance of **GetStream**.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type)