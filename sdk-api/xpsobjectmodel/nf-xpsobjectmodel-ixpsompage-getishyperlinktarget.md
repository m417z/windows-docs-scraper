# IXpsOMPage::GetIsHyperlinkTarget

## Description

Gets a Boolean value that indicates whether the page is the target of a hyperlink.

## Parameters

### `isHyperlinkTarget` [out, retval]

A Boolean value that indicates whether the page is the target of a hyperlink.

| Value | Meaning |
| --- | --- |
| **TRUE** | The page is the target of a hyperlink. |
| **FALSE** | The page is not the target of a hyperlink. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *isHyperlinkTarget* is **NULL**. |

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))