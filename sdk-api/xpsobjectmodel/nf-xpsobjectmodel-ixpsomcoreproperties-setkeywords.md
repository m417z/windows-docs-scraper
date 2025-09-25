# IXpsOMCoreProperties::SetKeywords

## Description

Sets the **keywords** property.

## Parameters

### `keywords` [in]

The string that contains the keywords to be written to the **keywords** property. A **NULL** pointer clears the **keywords** property.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The **keywords** property is a delimited set of keywords that are used to support searching and
indexing. It is typically a list of terms that are not
available elsewhere in the properties.

## See also

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)