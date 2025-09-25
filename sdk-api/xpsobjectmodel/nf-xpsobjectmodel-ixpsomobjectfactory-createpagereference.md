# IXpsOMObjectFactory::CreatePageReference

## Description

Creates an [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface that enables the virtualization of pages.

## Parameters

### `advisoryPageDimensions` [in]

The [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure that sets the advisory page dimensions (page width and page height).

Size is described in XPS units. There are 96 XPS units per inch. For example, the dimensions of an 8.5" by 11.0" page are 816 by 1,056 XPS units.

### `pageReference` [out, retval]

A pointer to the new [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *advisoryPageDimensions* or *pageReference* is **NULL**. |
| **XPS_E_INVALID_PAGE_SIZE** | *advisoryPageDimensions* contains an invalid page size or invalid page size values. |

## Remarks

 The use of a page reference makes it possible to delay the loading of the full object model of a page until the loading is requested explicitly. If the page has not been altered, it can be unloaded on request.

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMPageReference    *newInterface;
// The following value is defined outside of
// this example.
XPS_SIZE        advisoryPageDimensions;

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
    hr = xpsFactory->CreatePageReference (
        &advisoryPageDimensions,
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

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size)