# IXpsOMPage::SetName

## Description

Sets the **Name** property of this page.

## Parameters

### `name` [in]

A pointer to the name string to be set as the page's **Name** property. A **NULL** pointer clears any previously assigned name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_NAME** | The name string contains a character that is not valid. |

## Remarks

The **Name** property identifies the current page as a named, addressable point in a document, allowing the page to be referenced by a hyperlink.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))