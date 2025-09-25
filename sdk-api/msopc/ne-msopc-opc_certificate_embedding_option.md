# OPC_CERTIFICATE_EMBEDDING_OPTION enumeration

## Description

Describes the storage location of a certificate that is used in signing.

## Constants

### `OPC_CERTIFICATE_IN_CERTIFICATE_PART:0`

The certificate is stored in a part specific to the certificate.

### `OPC_CERTIFICATE_IN_SIGNATURE_PART:1`

The certificate is encoded within the signature markup in the Signature part.

### `OPC_CERTIFICATE_NOT_EMBEDDED:2`

The certificate is not stored in the package.

**Important** The certificate is contextual and understood between the signer and the verifier.

## See also

[Certificates](https://learn.microsoft.com/windows/desktop/SecCrypto/certificates)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcSigningOptions::GetCertificateEmbeddingOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-getcertificateembeddingoption)

[IOpcSigningOptions::SetCertificateEmbeddingOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setcertificateembeddingoption)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**

[W3C Recommendation, Canonical XML
Version 1.0](https://www.w3.org/TR/xml-c14n)