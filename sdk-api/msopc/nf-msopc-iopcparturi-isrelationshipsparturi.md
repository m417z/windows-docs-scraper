# IOpcPartUri::IsRelationshipsPartUri

## Description

Returns a value that indicates whether the current part URI object represents the part name of a Relationships part.

## Parameters

### `isRelationshipUri` [out, retval]

Receives a value that indicates whether the current part URI object represents the part name of a Relationships part.

| Value | Meaning |
| --- | --- |
| **TRUE** | The current part URI object represents the part name of a Relationships part. |
| **FALSE** | The current part URI object does not represent the part name of a Relationships part. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *isRelationshipUri* parameter is **NULL**. |

## Remarks

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**