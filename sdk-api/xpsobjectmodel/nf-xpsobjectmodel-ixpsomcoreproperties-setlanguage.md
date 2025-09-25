# IXpsOMCoreProperties::SetLanguage

## Description

Sets the **language** property.

## Parameters

### `language` [in]

The string that contains the language value to be written to the **language** property. A **NULL** pointer clears the **language** property.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The **language** property describes the language of the resource's intellectual content.

Internet Engineering Task Force (IETF) RFC 3066 describes the recommended encoding for this property.

## See also

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)