# IXpsOMPage::GetLanguage

## Description

Gets the **Language** property of the page.

## Parameters

### `language` [out, retval]

A language tag string that represents the language of the page contents. If the **Language** property has not been set, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *language* is **NULL**. |

## Remarks

The default value is the language tag string that is passed to [IXpsOMObjectFactory::CreatePage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomobjectfactory-createpage) in the *language* parameter.

Internet Engineering Task Force (IETF) RFC 3066 describes the recommended encoding of the language tag string that is returned in *language*.

This method allocates the memory used by the string that is returned in *language*. If *language* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[The Internet Engineering Task Force (IETF) RFC 3066](http://tools.ietf.org/html/rfc3066)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))