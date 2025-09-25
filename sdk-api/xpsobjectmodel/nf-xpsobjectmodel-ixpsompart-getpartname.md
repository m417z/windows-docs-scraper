# IXpsOMPart::GetPartName

## Description

Gets the name that will be used when the part is serialized.

## Parameters

### `partUri` [out, retval]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name. If the part name has not been set (by the [SetPartName](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompart-setpartname) method), a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *partUri* is **NULL**. |

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMPart](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompart)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))