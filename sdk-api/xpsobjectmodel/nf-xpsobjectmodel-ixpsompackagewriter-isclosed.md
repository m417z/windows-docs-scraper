# IXpsOMPackageWriter::IsClosed

## Description

Gets the status of the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface.

## Parameters

### `isClosed` [out, retval]

A pointer to a Boolean variable that receives the status of the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface.

| Value | Meaning |
| --- | --- |
| **TRUE** | The package is closed and no more content can be added. |
| **FALSE** | The package is open and content can be added. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_UNAVAILABLE_PACKAGE** | A severe error occurred and the contents of the XPS OM might be unrecoverable. Some components of the XPS OM might still be usable but only after they have been verified. Because the state of the XPS OM cannot be predicted after this error is returned, all components of the XPS OM should be released and discarded. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

If the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface is closed, operations on the package are not allowed.

## See also

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Using the IXpsOMPackageWriter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/dd464658(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))