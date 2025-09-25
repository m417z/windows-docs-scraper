# IOpcRelationshipSelector::GetSelectorType

## Description

Gets a value that describes how relationships are selected to be referenced for signing.

## Parameters

### `selector` [out, retval]

A value that describes which [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship) interface property will be compared to the string returned by the [GetSelectionCriterion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationshipselector-getselectioncriterion) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *selector* parameter is **NULL**. |

## Remarks

The following table shows how [OPC_RELATIONSHIP_SELECTOR](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationship_selector) values map to the relationship type and relationship identifier properties.

| [OPC_RELATIONSHIP_SELECTOR](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationship_selector) Value | Relationship Property | Description |
| --- | --- | --- |
| **OPC_RELATIONSHIP_SELECT_BY_TYPE** | Relationship type | Selects relationships that have a relationship type that matches *selectionCriterion* string. |
| **OPC_RELATIONSHIP_SELECT_BY_ID** | Relationship identifier | Selects relationships that have a relationship identifier that matches *selectionCriterion* string. |

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector)

[IOpcRelationshipSelectorEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorenumerator)

[IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**