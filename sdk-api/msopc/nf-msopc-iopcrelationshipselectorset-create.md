# IOpcRelationshipSelectorSet::Create

## Description

Creates an [IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector) interface pointer to represent how a subset of relationships are selected to be signed, and adds the new pointer to the set.

## Parameters

### `selector` [in]

A value that describes how to interpret the string that is passed in *selectionCriterion*.

### `selectionCriterion` [in]

A string that is interpreted to yield a criterion.

### `relationshipSelector` [out, retval]

A new [IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector) interface pointer that represents how relationships are selected from a Relationships part.

This parameter can be **NULL** if a pointer to the new interface is not needed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *selector* parameter is not a valid [OPC_RELATIONSHIP_SELECTOR](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationship_selector) enumeration value. |
| **E_POINTER** | The *partUri* parameter is **NULL**. |

## Remarks

Use the methods of the [IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector) interface pointers in the set to select relationships for signing.

When an [IOpcRelationshipSelector](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselector) interface pointer is created and added to the set, the criterion it provides access to is saved when the package is saved.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset)

[OPC_RELATIONSHIP_SELECTOR](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationship_selector)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**