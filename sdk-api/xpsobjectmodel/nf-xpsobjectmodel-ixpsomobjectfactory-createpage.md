# IXpsOMObjectFactory::CreatePage

## Description

Creates an [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface, which provides the root node of a tree of objects that represent the contents of a single page.

## Parameters

### `pageDimensions` [in]

The [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure that specifies the size of the page to be created.

Size is described in XPS units. There are 96 XPS units per inch. For example, the dimensions of an 8.5" by 11.0" page are 816 by 1,056 XPS units.

### `language` [in]

The string that indicates the default language of the created page.

**Important** The language string must follow the RFC 3066 syntax.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource.

### `page` [out, retval]

A pointer to the new [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pageDimensions*, *partUri*, or *page* is **NULL**. |
| **XPS_E_INVALID_LANGUAGE** | *language* does not contain a valid language string. |
| **XPS_E_INVALID_PAGE_SIZE** | *pageDimensions* contains an invalid page size or invalid page size values. |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMPage        *newInterface;
// The following values are defined outside of
// this example.
//  LPWSTR        language;
//  XPS_SIZE      pageDimensions;

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
    hr = xpsFactory->CreatePartUri(partUriString, &partUri);
    if (SUCCEEDED(hr))
    {
        hr = xpsFactory->CreatePage (
            &pageDimensions,
            language,
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

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[The Internet Engineering Task Force (IETF) RFC 3066](http://tools.ietf.org/html/rfc3066)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))