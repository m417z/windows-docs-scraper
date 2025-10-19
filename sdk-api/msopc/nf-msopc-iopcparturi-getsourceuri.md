# IOpcPartUri::GetSourceUri

## Description

Gets the source URI of the relationships that are stored in a Relationships part. The current part URI object represents the part name of that Relationships part.

## Parameters

### `sourceUri` [out, retval]

A pointer to the [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) interface of the OPC URI object that represents the URI of the source of the relationships stored in the Relationships part.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *sourceUri* parameter is **NULL**. |
| **OPC_E_RELATIONSHIP_URI_REQUIRED**<br><br>0x80510003 | The part name of a Relationships part is required, but the part name is not that of a Relationships part.<br><br>For more information about the part names of Relationships parts, see the *OPC*. |
| **CreateUri function error** | An **HRESULT** error code from the [CreateUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775098(v=vs.85)) function. |
| **WinINet error** | An **HRESULT** error code from a [WinINet](https://learn.microsoft.com/windows/desktop/WinInet/wininet-reference) API. |

## Remarks

If the current part URI object represents the part name of the Relationships part that stores package relationships ("/_rels/.rels"), the OPC URI object returned in *sourceUri* will represent the package root ("/").

If the current part URI object is not the part name of a Relationships part, this method fails with the **OPC_E_RELATIONSHIP_URI_REQUIRED** error. The syntax for Relationship part names is specified in the *OPC*.

The following table shows possible current part URIs and the source URI that would be returned by this method.

| Current Part URI | Current Part URI Description | Source URI | Source URI Description | Return Value |
| --- | --- | --- | --- | --- |
| /mydoc/_rels/picture.jpg.rels | The part name of a Relationships part | /mydoc/picture.jpg | The part name of the part that is the source of the relationships stored in the Relationships part that is represented by the current part URI object | **S_OK** |
| /_rels/.rels | The part name of a Relationships part | / | The package root; the source of the relationships stored in the Relationships part that is represented by the current part URI object | **S_OK** |
| /mydoc/image/chart1.jpg | The part name of a part that is not a Relationships part | Undefined | Undefined | **OPC_E_RELATIONSHIP_URI_REQUIRED** |
| /_rels/a.jpg | The part name of a part that is not a Relationships part | Undefined | Undefined | **OPC_E_RELATIONSHIP_URI_REQUIRED** |

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**