# IOpcRelationship::GetTargetUri

## Description

Gets the URI of the relationship target.

## Parameters

### `targetUri` [out, retval]

A pointer to the [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) interface of the URI that represents the URI of the relationship's target.

If the relationship target is internal, the target is a part and the URI of the target is relative to the URI of the source part.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *targetUri* parameter is **NULL**. |

## Remarks

The definitive way to find a part of interest is by using a relationship type.

Finding a part of interest requires several steps. For detailed information about finding a part, see the [Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview) and [Finding the Core Properties Part](https://learn.microsoft.com/previous-versions/windows/desktop/opc/finding-the-core-properties-part).

To determine whether the target of the relationship is internal or external, call the **GetTargetUri** method.

If the relationship target is internal, the target is a part.

If the relationship target is a part, the URI in *targetUri* is relative to the URI of the relationship source.

If the relationship target is a part, form the part name by calling the [IOpcUri::CombinePartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcuri-combineparturi) method from the [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) interface pointer received in *sourceUri* parameter of the [GetSourceUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationship-getsourceuri) method. Use the relative URI received in *targetUri* as the input parameter of the **IOpcUri::CombinePartUri** call. For an example, see [Resolving a Part Name from a Target URI](https://learn.microsoft.com/previous-versions/windows/desktop/opc/resolving-a-part-name-from-a-relationship-s-target-uri).

For more information about relationships, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationship)

[OPC_URI_TARGET_MODE](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_uri_target_mode)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)

[Resolving a Part Name from a Target URI](https://learn.microsoft.com/previous-versions/windows/desktop/opc/resolving-a-part-name-from-a-relationship-s-target-uri)