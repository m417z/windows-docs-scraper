# IXpsOMCoreProperties::GetContentType

## Description

Gets the **contentType** property.

## Parameters

### `contentType` [out, retval]

The string that is read from the **contentType** property.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *contentType* is **NULL**. |

## Remarks

The **contentType** property stores the type of content that is being represented, and it is generally defined by a
specific use and intended audience. Examples of **contentType** values include **Whitepaper**, **Security Bulletin**, and **Exam**.

This method allocates the memory used by the string that is returned in *contentType*. If *contentType* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))