# IOpcRelationshipSet::GetRelationshipsContentStream

## Description

 Gets a read-only stream that contains the part content of the Relationships part represented by the set.

## Parameters

### `contents` [out, retval]

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the read-only stream that contains the part content of the Relationships part represented by the set.

If the relationships stored in the Relationships part have not been modified, part content can include markup compatibility data that is not otherwise accessible through the relationship objects in the set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *contents* parameter is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

Calling this method will parse and validate all the relationships in the relationships markup. If the Relationships part contains invalid relationships markup, the markup cannot be retrieved by this method.

For more information about markup compatibility and packages, see Part 5: Markup Compatibility in [ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/) (https://www.ecma-international.org/publications-and-standards/standards/ecma-376/).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)