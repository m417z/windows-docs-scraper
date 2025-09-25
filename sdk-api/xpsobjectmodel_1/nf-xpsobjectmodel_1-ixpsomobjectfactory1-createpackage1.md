## Description

Creates an [IXpsOMPackage1](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1) interface that serves as the root node of an XPS object model document tree.

## Parameters

### `package`

A pointer to the new [IXpsOMPackage1](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1) interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see XPS Document Errors.
| Return code | Description |
|-------------|-----------------------|
| S_OK | The method succeeded. |
| E_POINTER | *package* is NULL. |

## Remarks

## See also

[Create a Blank XPS OM](https://docs.microsoft.com/previous-versions/windows/desktop/dd316970(v=vs.85))

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)

[IXpsOMPackage1](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://docs.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))