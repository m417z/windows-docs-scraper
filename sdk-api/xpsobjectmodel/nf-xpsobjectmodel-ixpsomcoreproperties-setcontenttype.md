# IXpsOMCoreProperties::SetContentType

## Description

Sets the **contentType** property.

## Parameters

### `contentType` [in]

The string to be written to the **contentType** property. A **NULL** pointer clears the **contentType** property.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The **contentType** property contains the type of content that is being represented, which is generally defined by a
specific use and intended audience. Examples of **contentType** values include **Whitepaper**, **Security Bulletin**, and **Exam**.

## See also

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)