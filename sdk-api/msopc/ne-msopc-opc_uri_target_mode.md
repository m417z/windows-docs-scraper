# OPC_URI_TARGET_MODE enumeration

## Description

Indicates the target mode of a relationship.

## Constants

### `OPC_URI_TARGET_MODE_INTERNAL:0`

The target of the relationship is a part inside the package.

### `OPC_URI_TARGET_MODE_EXTERNAL:1`

The target of the relationship is a resource outside of the package.

## Remarks

If the relationship's target mode is **OPC_URI_TARGET_MODE_INTERNAL** the URI of the target part is relative to the URI of the source of the relationship.

To get the URI of the target of the relationship, call the [IOpcRelationship::GetTargetUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationship-gettargeturi) method.

For more information about relationships, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

## See also

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship)

[IOpcRelationshipSet::CreateRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationshipset-createrelationship)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)