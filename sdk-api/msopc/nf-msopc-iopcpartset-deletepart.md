# IOpcPartSet::DeletePart

## Description

Deletes the [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointer of a specified part object from the set.

## Parameters

### `name` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object that represents the part name.

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

When an [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointer is deleted from the set, the part it represents is not serialized when the package is serialized. Additionally, if the represented part is the source of one or more relationships, those relationships are not saved with the package when the package object is written.

The data contained in a deleted part object is accessible until the package object that contains the deleted part object is released. Additionally, a Relationship whose source is the part that is represented by the deleted part object also remains accessible until the package object that contains the deleted part object is released. However, these relationships will not be saved when the package is saved.

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

**Reference**