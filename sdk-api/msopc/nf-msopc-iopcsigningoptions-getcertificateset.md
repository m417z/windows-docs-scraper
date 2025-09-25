# IOpcSigningOptions::GetCertificateSet

## Description

Gets an [IOpcCertificateSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateset) interface pointer.

## Parameters

### `certificateSet` [out, retval]

An [IOpcCertificateSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateset) interface pointer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *certificateSet* parameter is **NULL**. |

## Remarks

This method gets a set that provides methods enabling the addition and removal of certificates from a certificate chain that will be associated with the signature when it is generated.

Do not include the certificate use to generate the signature in this set. This certificate, the signer certificate, is required for signature generation. To generate the signature, call the [IOpcDigitalSignatureManager::Sign](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignaturemanager-sign) method with the *certificate* parameter value set to a pointer to the signer certificate.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**