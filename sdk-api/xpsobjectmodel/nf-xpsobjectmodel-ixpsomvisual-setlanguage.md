# IXpsOMVisual::SetLanguage

## Description

Sets the **Language** property of the visual.

## Parameters

### `language` [in]

The language string that specifies the language of the visual and of its contents. A **NULL** pointer clears the **Language** property.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_LANGUAGE** | The value of *language* is formatted incorrectly or specifies a language that is not valid. |

## Remarks

The recommended encoding for the **Language** property is specified in Internet Engineering Task Force (IETF) RFC 3066r.

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))