# IXpsOMObjectFactory::CreatePackage

## Description

Creates an [IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage) interface that serves as the root node of an XPS object model document tree.

## Parameters

### `package` [out, retval]

A pointer to the new [IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *package* is **NULL**. |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMPackage    *newInterface;

// Note the implicit requirement that CoInitializeEx
//  has previously been called from this thread.

hr = CoCreateInstance(
      __uuidof(XpsOMObjectFactory),
      NULL,
      CLSCTX_INPROC_SERVER,
      __uuidof(IXpsOMObjectFactory),
      reinterpret_cast<LPVOID*>(&xpsFactory)
      );

if (SUCCEEDED(hr))
{
    hr = xpsFactory->CreatePackage (&newInterface);
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

For information about using [IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage) interface in a program, see [Create a Blank XPS OM](https://learn.microsoft.com/previous-versions/windows/desktop/dd316970(v=vs.85)).

## See also

[Create a Blank XPS OM](https://learn.microsoft.com/previous-versions/windows/desktop/dd316970(v=vs.85))

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))