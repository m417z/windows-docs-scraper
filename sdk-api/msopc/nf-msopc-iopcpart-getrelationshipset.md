# IOpcPart::GetRelationshipSet

## Description

Gets a relationship set object that represents the Relationships part that stores relationships that have the part as their source.

## Parameters

### `relationshipSet` [out, retval]

A pointer to a relationship set object that represents the Relationships part that stores all relationships that have the part as their source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *relationshipSet* parameter is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

The definitive way to find a part of interest is by using a relationship type to find the relationship that has the part of interest as its target. The target's URI can then be resolved to a part name which is used to access the part.

For more information about using the relationship type to find a relationship and then a part of interest, see [IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset) and [IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship).

For more information about parts and relationships, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)