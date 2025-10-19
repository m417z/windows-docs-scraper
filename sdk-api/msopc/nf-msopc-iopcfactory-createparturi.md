# IOpcFactory::CreatePartUri

## Description

Creates a part URI object that represents a part name.

## Parameters

### `pwzUri` [in]

A URI that represents the location of a part relative to the root of the package that contains it.

### `partUri` [out, retval]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object. This object represents the part name derived from the URI passed in *pwzUri*.

Part names must conform to the syntax specified in the *OPC*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *pwzUri* and *partUri* parameters is **NULL**. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot be the empty string "". |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot be a '/'. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot begin with "//". |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot end with a '/'. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot end with a '.'. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot have any segments that end with a '.'. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot have fragment component. A fragment component is preceded by a '#' character, as described in [RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt). |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | A part name cannot be the name of a Relationships part that indicates another Relationships part as the source of the relationships contained therein. |
| **OPC_E_RELATIVE_URI_REQUIRED**<br><br>0x80510002 | A part name cannot be an absolute URI. An absolute URI begins with a schema component followed by a ":", as described in [RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt). |
| **CreateUri function error** | An **HRESULT** error code from the [CreateUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775098(v=vs.85)) function. |
| **WinINet error** | An **HRESULT** error code from a [WinINet](https://learn.microsoft.com/windows/desktop/WinInet/wininet-reference) API. |

## Remarks

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[CreateUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775098(v=vs.85))

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

[RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt)

**Reference**