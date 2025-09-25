# IXpsOMObjectFactory::CreateColorProfileResource

## Description

Creates an [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface, which is used to access a color profile resource stream.

## Parameters

### `acquiredStream` [in]

The read-only [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface to be associated with this resource. This parameter must not be **NULL**.

**Important** Treat this stream as a Single-Threaded Apartment (STA) object; do not re-enter it.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource.

### `colorProfileResource` [out, retval]

A pointer to the new [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *acquiredStream*, *partUri*, or *colorProfileResource* is **NULL**. |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMColorProfileResource    *newInterface;
IOpcPartUri                   *partUri;

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
    hr = xpsFactory->CreatePartUri(
        partUriString,
        &partUri);
    if (SUCCEEDED(hr))
    {
        hr = xpsFactory->CreateColorProfileResource (
            acquiredStream,
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

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))