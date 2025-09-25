# IOpcRelationship::GetId

## Description

Gets the unique identifier of the relationship.

## Parameters

### `relationshipIdentifier` [out, retval]

The identifier of the relationship.

The identifier of a relationship is arbitrary and local to the package, and, therefore, .

Valid identifiers conform to the restrictions for **xsd:ID**, which are documented in section 3.3.8 ID of the [W3C Recommendation, XML Schema Part 2: Datatypes Second Edition](https://www.w3.org/TR/xmlschema-2/#ID) (http://www.w3.org/TR/xmlschema-2/#ID).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *relationshipIdentifier* parameter is **NULL**. |

## Remarks

The identifier of a relationship is not useful for finding relationships because it is arbitrary and local to the package.

The definitive way to find a part of interest is by using a relationship type.

Finding a part requires several steps. For detailed information about finding a part, see [Finding the Core Properties Part](https://learn.microsoft.com/previous-versions/windows/desktop/opc/finding-the-core-properties-part).

This method allocates memory used by the string returned in *relationshipIdentifier*. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

For more information about relationships, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Finding the Core Properties Part](https://learn.microsoft.com/previous-versions/windows/desktop/opc/finding-the-core-properties-part)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship)

[IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)

[W3C Recommendation, XML Schema Part 2: Datatypes Second Edition](https://www.w3.org/TR/xmlschema-2/#ID)