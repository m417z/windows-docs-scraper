# IXpsOMObjectFactory::CreateSolidColorBrush

## Description

Creates an [IXpsOMSolidColorBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsolidcolorbrush) interface, which specifies a brush of a single, solid color.

## Parameters

### `color` [in]

The [XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85)) structure that specifies the brush color.

### `colorProfile` [in]

The [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface. Unless the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type), this value must be **NULL**.

### `solidColorBrush` [out, retval]

A pointer to the new [IXpsOMSolidColorBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsolidcolorbrush) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *color* or *solidColorBrush* is **NULL**. |
| **XPS_E_MISSING_COLORPROFILE** | *colorProfile* is **NULL** when a color profile is expected. A color profile is required when the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). |
| **XPS_E_NO_CUSTOM_OBJECTS** | *colorProfile* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |
| **XPS_E_UNEXPECTED_COLORPROFILE** | *colorProfile* contains a color profile when one is not expected. A color profile is required only when the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMSolidColorBrush             *newInterface;
// The following values are defined outside of
// this example.
//  XPS_COLOR                     color;
//  IXpsOMColorProfileResource    *colorProfile;

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
    hr = xpsFactory->CreateSolidColorBrush (
        &color,
        colorProfile,
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

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMSolidColorBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsolidcolorbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85))