# IOpcRelationship::GetTargetMode

## Description

Gets a value that describes whether the relationship's target is internal or external to the package.

## Parameters

### `targetMode` [out, retval]

A value that describes whether the relationship's target is internal or external to the package.

If the target of the relationship is internal, the target is a part.

If the target of the relationship is external, the target is a resource outside of the package.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *targetMode* parameter is **NULL**. |

## Remarks

If the relationship target is internal, the target is a part. The URI of the target is relative to the URI of the source part.

To get the URI of the target of the relationship, call the [IOpcRelationship::GetTargetUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcrelationship-gettargeturi) method.

The definitive way to find a part of interest is by using a relationship type.

Finding a part of interest requires several steps. For detailed information about finding a part, see the [Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview) and [Finding the Core Properties Part](https://learn.microsoft.com/previous-versions/windows/desktop/opc/finding-the-core-properties-part).

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

[OPC_URI_TARGET_MODE](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_uri_target_mode)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)