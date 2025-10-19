# IOpcUri::GetRelationshipsPartUri

## Description

Gets the part name of the Relationships part that stores relationships that have the source URI represented by the current OPC URI object.

## Parameters

### `relationshipPartUri` [out, retval]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object that represents the part name of the Relationships part. The source URI of the relationships stored in this Relationships part is represented by the current OPC URI object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *relationshipPartUri* parameter is **NULL**. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | The current [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) represents a Relationships part and cannot be the source of any relationships. |
| **CreateUri function error** | An **HRESULT** error code from the [CreateUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775098(v=vs.85)) function. |
| **WinINet error** | An **HRESULT** error code from a [WinINet](https://learn.microsoft.com/windows/desktop/WinInet/wininet-reference) API. |

## Remarks

The following table shows Relationships part URIs for some OPC URIs.

| OPC URI | Relationships Part Name | Return Value |
| --- | --- | --- |
| /mydoc/images/picture.jpg | /mydoc/images/_rels/picture.jpg.rels | **S_OK** |
| / | /_rels/.rels | **S_OK** |
| /mydoc/images/_rels/picture.jpg.rels | Undefined | **OPC_E_NONCONFORMING_URI** |

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**