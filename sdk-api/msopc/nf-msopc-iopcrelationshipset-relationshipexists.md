# IOpcRelationshipSet::RelationshipExists

## Description

Gets a value that indicates whether a specified relationship is represented as a relationship object in the set.

## Parameters

### `relationshipIdentifier` [in]

The unique identifier of a relationship.

### `relationshipExists` [out, retval]

One of the following values:

| Value | Meaning |
| --- | --- |
| **TRUE** | A relationship that has the identifier specified in *relationshipIdentifier* is represented in the set. |
| **FALSE** | A relationship that has the identifier specified in *relationshipIdentifier* is not represented in the set. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *relationshipIdentifier* and *relationshipExists* parameters is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

If a relationship is represented in the set, the relationship is stored in the Relationships part represented by that set.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

**Reference**