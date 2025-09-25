# IXpsOMCoreProperties::SetContentStatus

## Description

Sets the **contentStatus** property.

## Parameters

### `contentStatus` [in]

The string to be written to the **contentStatus** property. A **NULL** pointer clears the **contentStatus** property.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The **contentStatus** property contains the status of the content. Examples of **contentStatus** values include **Draft**, **Reviewed**, and **Final**.

## See also

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)