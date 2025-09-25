# IXpsOMVisual::GetLanguage

## Description

Gets the **Language** property of the visual and of its contents.

## Parameters

### `language` [out, retval]

The language string that specifies the language of the page. If a language has not been set, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *language* is **NULL**. |

## Remarks

The **Language** property that is set by this method specifies the language of the resource content.

This method allocates the memory that is used by the string returned in *language*. If *language* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

Internet Engineering Task Force (IETF) RFC 3066 specifies the recommended encoding for the **Language** property.

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))