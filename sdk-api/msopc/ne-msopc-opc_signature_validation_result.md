# OPC_SIGNATURE_VALIDATION_RESULT enumeration

## Description

Indicates the status of the signature.

## Constants

### `OPC_SIGNATURE_VALID:0`

The signature is valid.

Signature validation using the provided certificate succeeded; signed package components have not been altered.

**Important** Signature trust decisions must be based on the validity of the signature as well as other format- and application-specific factors, including: validation of the identity of the package originator, signing policy, certificate quality, and possibly the existence of a valid time stamp.

### `OPC_SIGNATURE_INVALID:-1`

The signature is not valid.

Signature markup or signed package components might have been altered. Alternatively, the signature might not exist in the current package.

## See also

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**

[W3C Recommendation, XML Signature and Syntax Processing](https://www.w3.org/TR/xmldsig-core/)