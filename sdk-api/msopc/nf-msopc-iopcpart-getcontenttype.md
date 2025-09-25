# IOpcPart::GetContentType

## Description

Gets the media type of part content.

## Parameters

### `contentType` [out, retval]

The media type of part content, as specified by the package format designer and adhering to [RFC 2616: HTTP/1.1](https://www.w3.org/Protocols/rfc2616/rfc2616.html).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *contentType* parameter is **NULL**. |

## Remarks

This method allocates memory used by the string returned in *contentType*. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

For more information about parts, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

[RFC 2616: HTTP/1.1](https://www.w3.org/Protocols/rfc2616/rfc2616.html)

**Reference**