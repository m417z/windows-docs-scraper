# IOpcDigitalSignatureManager::Validate

## Description

Validates a specified package signature using a specified certificate.

## Parameters

### `signature` [in]

An [IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature) interface pointer that represents the signature to be validated.

### `certificate` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains a certificate that is used to validate the signature.

### `validationResult` [out, retval]

A value that describes the result of the validation check.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *signature*, *certificate*, and *validationResult* parameters is **NULL**. |

## Remarks

This method does not perform security checks on an X.509 Public Key Infrastructure Certificate; the caller must perform the checks for revocation, expiration, certificate chain, and all other necessary checks.

This method checks that the specified signature (signed entities and the signature markup) has not been altered since the signature was generated, but does not validate the identity of the signer.

**Important** The caller must validate the identity of the signer.

If there are errors in a package signature, some of these errors may not be exposed until this method is called.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Certificates](https://learn.microsoft.com/windows/desktop/SecCrypto/digital-certificates)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignatureManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignaturemanager)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Digital Signature Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-digital-signature-interfaces)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**