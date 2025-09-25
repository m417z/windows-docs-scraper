# OPC_RELATIONSHIPS_SIGNING_OPTION enumeration

## Description

Describes whether a reference represented by the [IOpcSignatureRelationshipReference](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsignaturerelationshipreference) interface refers to all or a subset of relationships represented as relationship objects in a relationship set object.

## Constants

### `OPC_RELATIONSHIP_SIGN_USING_SELECTORS:0`

The reference refers to a subset of relationships represented as relationship objects and identified using the [IOpcRelationshipSelectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipselectorset) interface.

### `OPC_RELATIONSHIP_SIGN_PART:1`

The reference refers to all of the relationships represented as relationship objects in the relationship set object.

## See also

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSignatureRelationshipReference::GetRelationshipSigningOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturerelationshipreference-getrelationshipsigningoption)

[IOpcSignatureRelationshipReferenceSet::Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturerelationshipreferenceset-create)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**