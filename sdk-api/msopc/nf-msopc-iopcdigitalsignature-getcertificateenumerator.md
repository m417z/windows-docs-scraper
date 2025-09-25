# IOpcDigitalSignature::GetCertificateEnumerator

## Description

Gets an enumerator of certificates that are used in the signature.

## Parameters

### `certificateEnumerator` [out, retval]

A pointer to an enumerator of pointers to [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures that are used in the signature.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *certificateEnumerator* parameter is **NULL**. |

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Certificates](https://learn.microsoft.com/windows/desktop/SecCrypto/digital-certificates)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator)

[IOpcCertificateSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateset)

[IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**