# IOpcRelationship::GetRelationshipType

## Description

Gets the relationship type.

## Parameters

### `relationshipType` [out, retval]

Receives the relationship type, which is the qualified name of the relationship, as defined by the package format designer or the *OPC*.

For more information about relationship types see Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *relationshipType* parameter is **NULL**. |

## Remarks

This method allocates memory used by the string returned in *relationshipType*. If the method succeeds, call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

The definitive way to find a part of interest is by using a relationship type.

Finding a part of interest requires several steps. For detailed information about finding a part, see [Finding the Core Properties Part](https://learn.microsoft.com/previous-versions/windows/desktop/opc/finding-the-core-properties-part).

For more information about relationships, relationship types and a list of relationship types defined by the OPC, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *OPC*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Finding the Core Properties Part](https://learn.microsoft.com/previous-versions/windows/desktop/opc/finding-the-core-properties-part)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship)

[IOpcRelationshipSet::GetEnumeratorForType](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationshipset-getenumeratorfortype)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)