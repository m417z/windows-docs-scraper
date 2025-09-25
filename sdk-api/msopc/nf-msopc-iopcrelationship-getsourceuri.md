# IOpcRelationship::GetSourceUri

## Description

Gets the URI of the relationship source.

## Parameters

### `sourceUri` [out, retval]

A pointer to the [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) interface of the OPC URI object that represents the URI of the relationship source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *sourceUri* parameter is **NULL**. |

## Remarks

If the source of a relationship is the package itself, the URI in *sourceUri* represents the package root: "/".

If the relationship target is a part, form the part name by calling the [IOpcUri::CombinePartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcuri-combineparturi) method from the [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) interface pointer received in *sourceUri*. Use the relative URI received in the *targetUri* parameter of the [GetTargetUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationship-gettargeturi) method as the input parameter of the **IOpcUri::CombinePartUri** call. For an example, see [Resolving a Part Name from a Target URI](https://learn.microsoft.com/previous-versions/windows/desktop/opc/resolving-a-part-name-from-a-relationship-s-target-uri).

For more information about relationships, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)

[Resolving a Part Name from a Target URI](https://learn.microsoft.com/previous-versions/windows/desktop/opc/resolving-a-part-name-from-a-relationship-s-target-uri)