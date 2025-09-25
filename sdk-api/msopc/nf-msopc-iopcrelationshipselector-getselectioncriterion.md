# IOpcRelationshipSelector::GetSelectionCriterion

## Description

Gets a string that is used to select relationships to be referenced for signing.

## Parameters

### `selectionCriterion` [out, retval]

A string used to select relationships to be referenced for signing.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *selectionCriterion* parameter is **NULL**. |

## Remarks

This method allocates memory used by the string returned in *selectionCriterion*. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

Use the [IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector) interface methods to select relationships for signing. A relationship is selected if its type or identifier matches the string that is retrieved by calling the **GetSelectionCriterion** method. This string is either a relationship type or a relationship identifier. Call the [GetSelectorType](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationshipselector-getselectortype) method to get an [OPC_RELATIONSHIP_SELECTOR](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationship_selector) value to determine whether the string is a relationship type or an identifier. To access these relationship properties, call the [IOpcRelationship::GetRelationshipType](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationship-getrelationshiptype) and [IOpcRelationship::GetId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationship-getid) methods.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship)

[IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector)

[IOpcRelationshipSelectorEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorenumerator)

[IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**