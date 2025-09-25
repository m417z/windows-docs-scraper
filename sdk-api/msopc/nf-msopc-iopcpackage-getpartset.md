# IOpcPackage::GetPartSet

## Description

Gets a part set object that contains [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointers.

## Parameters

### `partSet` [out, retval]

A pointer to the [IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset) interface of the part set object that contains [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface pointers to part objects.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *partSet* parameter is **NULL**. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

The [IOpcPart](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpart) interface is only used to represent parts in the package that are not Relationships parts.

For more information about packages, parts, relationships, and the interfaces that represent them, see the [Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview) and the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

[IOpcPackage](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpackage)

[IOpcPartSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpartset)

[IOpcRelationshipSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcrelationshipset)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packages Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packages-overview)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

**Reference**