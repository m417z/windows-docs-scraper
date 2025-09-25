# IXpsOMObjectFactory::CreateImageResource

## Description

Creates an [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface, which is used to access an image resource stream.

## Parameters

### `acquiredStream` [in]

The read-only stream to be associated with this resource. This parameter must not be **NULL**.

**Important** Treat this stream as a Single-Threaded Apartment (STA) object; do not re-enter it.

### `contentType` [in]

The [XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type) value that describes the image type of the stream that is referenced by *acquiredStream*.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource. This parameter must not be **NULL**.

### `imageResource` [out, retval]

A pointer to the new [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *contentType* was not a valid [XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type) value. |
| **E_POINTER** | *acquiredStream*, *partUri*, or *imageResource* is **NULL**. |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMImageResource    *newInterface;
// The following values are defined outside of
// this example.
//  IStream            *acquiredStream;
//  XPS_IMAGE_TYPE     contentType;
//  IOpcPartUri        *partUri;

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
    // The partUriString and acquiredStream variables
    //   are defined outside of this example.
    hr = xpsFactory->CreatePartUri(partUriString, &partUri);
    if (SUCCEEDED(hr))
    {
        hr = xpsFactory->CreateImageResource (
            acquiredStream,
            contentType,
            partUri,
            &newInterface);
        if (SUCCEEDED(hr))
        {
            // use newInterface

            newInterface->Release();
        }
        partUri->Release();
    }
    xpsFactory->Release();
}
else
{
    // evaluate HRESULT error returned in hr
}

```

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type)