# IOpcPartSet::CreatePart

## Description

Creates a part object that represents a part and adds a pointer to the object's [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface to the set.

## Parameters

### `name` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of a part URI object that represents the part name of the part.

To create a part URI object (which implements the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface) to represent the part name of the part, call the [IOpcFactory::CreatePartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-createparturi) method.

### `contentType` [in]

The media type of part content.

### `compressionOptions` [in]

A value that describes the way to compress the part content of the part.

### `part` [out, retval]

A pointer to the new [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) that represents the part.

This parameter cannot be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *name* parameter is **NULL**. |
| **E_INVALIDARG** | The value passed in the *compressionOptions* parameter is not a valid [OPC_COMPRESSION_OPTIONS](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_compression_options) enumeration value. |
| **OPC_E_DUPLICATE_PART**<br><br>0x8051000B | A part with the specified part name already exists in the current package. |
| **OPC_E_INVALID_CONTENT_TYPE**<br><br>0x80510044 | A content type does not conform to the rules for a valid media type, specified in [RFC 2616: HTTP/1.1](https://www.w3.org/Protocols/rfc2616/rfc2616.html) (http://www.w3.org/Protocols/rfc2616/rfc2616.html) and the *OPC*. |
| **OPC_E_UNEXPECTED_CONTENT_TYPE**<br><br>0x80510005 | Either the content type of a part differed from the expected content type (specified in the OPC, [ECMA-376 Part 2](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)), or the part content did not match the part's content type. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

When a part object is created and a pointer to it is added to the set, the part it represents is serialized when the package is serialized.

This method cannot create a part object that represents a Relationships part.

If part content is compressed prior to the creation of the part object, pass the **OPC_COMPRESSION_NONE** value in the *compressionOptions* parameter.

Part content that is already compressed will not compress significantly more.

An [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) provides access to the properties of a part. For details about these properties, see the [Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview) and the [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) topic.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory::CreatePartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-createparturi)

[IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset)

[OPC_COMPRESSION_OPTIONS](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_compression_options)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

[RFC 2616: HTTP/1.1](https://www.w3.org/Protocols/rfc2616/rfc2616.html)

**Reference**