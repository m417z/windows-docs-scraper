# IOpcPartSet::GetPart

## Description

Gets a part object, which represents a specified part, in the set.

## Parameters

### `name` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object that represents the part name of a part.

### `part` [out, retval]

A pointer to the [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) of the part object that represents the part that has the specified part name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *name* parameter is **NULL**. |
| **OPC_E_NO_SUCH_PART**<br><br>0x80510018 | The specified part does not exist. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

To retrieve the [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointer of the part object that represents a specific part, call the [PartExists](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcpartset-partexists) method and pass in the part name to confirm that the part is represented in the set. If it is, call the **GetPart** method and pass in the part name to retrieve the **IOpcPart** interface pointer.

If the part URI object represents the part name of a Relationships part, this method will fail because Relationships parts are not included in the set.

The [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface provides access to the properties of a part. For details about these properties, see the [Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview) and [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

**Reference**