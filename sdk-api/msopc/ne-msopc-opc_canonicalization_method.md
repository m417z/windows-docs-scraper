# OPC_CANONICALIZATION_METHOD enumeration

## Description

Describes the canonicalization method to be applied to XML markup.

## Constants

### `OPC_CANONICALIZATION_NONE:0`

No canonicalization method is applied.

### `OPC_CANONICALIZATION_C14N:1`

The C14N canonicalization method that removes comments is applied.

### `OPC_CANONICALIZATION_C14N_WITH_COMMENTS:2`

The C14N canonicalization method that preserves comments is applied.

## Remarks

For more information about XML canonicalization, see the [W3C Recommendation, Canonical XML
Version 1.0](https://www.w3.org/TR/xml-c14n) (http://www.w3.org/TR/xml-c14n).

For more information about canonicalization and packages, see the *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)*.

## See also

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature::GetCanonicalizationMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignature-getcanonicalizationmethod)

[IOpcSignaturePartReference::GetTransformMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturepartreference-gettransformmethod)

[IOpcSignaturePartReferenceSet::Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturepartreferenceset-create)

[IOpcSignatureReference::GetTransformMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturereference-gettransformmethod)

[IOpcSignatureReferenceSet::Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturereferenceset-create)

[IOpcSignatureRelationshipReference::GetTransformMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturerelationshipreference-gettransformmethod)

[IOpcSignatureRelationshipReferenceSet::Create](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsignaturerelationshipreferenceset-create)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**

[W3C Recommendation, Canonical XML
Version 1.0](https://www.w3.org/TR/xml-c14n)