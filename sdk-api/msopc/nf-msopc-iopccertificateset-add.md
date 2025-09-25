# IOpcCertificateSet::Add

## Description

Adds a certificate to the set.

## Parameters

### `certificate` [in]

A
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)
structure that contains the certificate to be added.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to,
those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *certificate* parameter is **NULL**. |

## Remarks

Certificates that are in a certificate chain are added to the package by calling the
**Add** method.

When a signature is
generated, certificates that were added to the package by calling
**Add** are associated with the signature.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the
[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Certificates](https://learn.microsoft.com/windows/desktop/SecCrypto/certificates)

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcCertificateSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**