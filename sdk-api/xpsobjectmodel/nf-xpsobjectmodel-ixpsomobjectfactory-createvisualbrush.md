# IXpsOMObjectFactory::CreateVisualBrush

## Description

Creates an [IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush) interface, which is an [IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush) that uses a visual object.

## Parameters

### `viewBox` [in]

The [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that specifies the source image's area to be used in the brush. This parameter must not be **NULL**.

### `viewPort` [in]

The [XPS_RECT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_rect) structure that specifies the destination geometry area of the tile. This parameter must not be **NULL**.

### `visualBrush` [out, retval]

A pointer to the new [IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *viewBox*, *viewPort*, or *visualBrush* is **NULL**. |
| **E_INVALIDARG** | *viewBox* or *viewPort* contains an invalid rectangle or value. |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMVisualBrush        *newInterface;

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
    hr = xpsFactory->CreateVisualBrush (
        &viewBox,
        &viewPort,
        &newInterface);

    if (SUCCEEDED(hr))
    {
        // assign visual using one of the following:
        newInterface->SetVisualLocal (localVisual);
        // or
        newInterface->SetVisualLookup (visualLookupKey);
        // use newInterface

        newInterface->Release();
    }
    xpsFactory->Release();
}
else
{
    // evaluate HRESULT error returned in hr
}
// use newInterface

newInterface->Release();
xpsFactory->Release();

```

## See also

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))