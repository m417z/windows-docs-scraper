# IOpcRelationshipSet::GetEnumerator

## Description

Gets an enumerator of [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship) interface pointers in the set.

## Parameters

### `relationshipEnumerator` [out, retval]

A pointer to the [IOpcRelationshipEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipenumerator) interface of the enumerator of [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship) interface pointers in the set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *relationshipEnumerator* parameter is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)