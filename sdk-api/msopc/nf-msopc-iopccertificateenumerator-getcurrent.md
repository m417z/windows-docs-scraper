# IOpcCertificateEnumerator::GetCurrent

## Description

Gets the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure at the current position of the enumerator.

## Parameters

### `certificate` [out, retval]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.
If the method succeeds, call the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function to free the memory of the structure.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *partReference* parameter is **NULL**. |
| **OPC_E_ENUM_COLLECTION_CHANGED**<br><br>0x80510050 | The enumerator is invalid because the underlying set has changed. |
| **OPC_E_ENUM_INVALID_POSITION**<br><br>0x80510053 | The enumerator cannot perform this operation from its current position. |
| **OPC_E_DS_EXTERNAL_SIGNATURE**<br><br>0x8051001E | A relationship whose target is a Signature part has the external target mode; Signature parts must be inside of the package. |
| **OPC_E_DS_INVALID_CERTIFICATE_RELATIONSHIP**<br><br>0x8051001D | A relationship of type digital signature certificate has the external target mode.<br><br>For more information about this relationship type, see the *OPC*. |
| **OPC_E_DS_INVALID_RELATIONSHIP_TRANSFORM_XML**<br><br>0x80510021 | A **Transform** element that indicates the use of the relationships transform and the selection criteria for the transform does not conform to the schema specified in the *OPC*. |
| **OPC_E_DS_MISSING_CERTIFICATE_PART**<br><br>0x80510056 | The part that contains the certificate and is the target of a relationship of type digital signature certificate does not exist.<br><br>For more information about this relationship type, see the *OPC*. |
| **OPC_E_DS_SIGNATURE_PROPERTY_MISSING_TARGET**<br><br>0x80510045 | The **SignatureProperty** element is missing the required **Target** attribute. |
| **OPC_E_UNEXPECTED_CONTENT_TYPE**<br><br>0x80510005 | Either the content type of a part differed from the expected content type (specified in the OPC, [ECMA-376 Part 2](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)), or the part content did not match the part's content type. |

## Remarks

If the certificate represented by the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure is corrupted or is not an X.509 certificate, this method will return an error; further, the signing policy used by the caller dictates whether the signature will still be validated. After this kind of error is returned, calls to the [MoveNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopccertificateenumerator-movenext) or [MovePrevious](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopccertificateenumerator-moveprevious) method will continue to iterate through the enumerator.

When an enumerator is created, the current position precedes the first pointer of the enumerator. To set the current position to the first pointer, call the [MoveNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopccertificateenumerator-movenext) method after the enumerator is created.

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Certificates](https://learn.microsoft.com/windows/desktop/SecCrypto/certificates)

[Core Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/opc/core-packaging-interfaces)

[Digital Signatures Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/digital-signatures-overview)

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcCertificateEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateenumerator)

[IOpcCertificateSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopccertificateset)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**