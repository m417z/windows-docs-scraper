# IXpsOMPage::SetLanguage

## Description

Sets the **Language** property of the page.

## Parameters

### `language` [in]

A language tag string that represents the language of the page content. A **NULL** pointer clears the previously assigned language.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_LANGUAGE** | The language string contains one or more language strings that are not valid. |

## Remarks

The language tag string must conform to the language tag syntax that is described in the Internet Engineering Task Force (IETF) RFC 3066. For more information, go to <http://tools.ietf.org/html/rfc3066>.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[The Internet Engineering Task Force (IETF) RFC 3066](http://tools.ietf.org/html/rfc3066)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))