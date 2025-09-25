# IXpsOMVisual::GetHyperlinkNavigateUri

## Description

Gets a pointer to the [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) interface to which this visual object links.

## Parameters

### `hyperlinkUri` [out, retval]

A pointer to the [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) interface that contains the destination URI for the link.
If a URI has not been set for this object, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *hyperlinkUri* is **NULL**. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))