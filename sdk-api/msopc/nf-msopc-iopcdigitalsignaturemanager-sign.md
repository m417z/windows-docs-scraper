# IOpcDigitalSignatureManager::Sign

## Description

 Signs the package by generating a signature by using the specified certificate and [IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions) interface pointer. The resultant signature is represented by an [IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature) interface pointer.

## Parameters

### `certificate` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate.

### `signingOptions` [in]

An [IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions) interface pointer that is used to generate the signature.

### `digitalSignature` [out, retval]

A new [IOpcDigitalSignature](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcdigitalsignature) interface pointer that represents the signature.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *certificate*, *signingOptions*, and *digitalSignature* parameters is **NULL**. |
| **OPC_E_DS_DEFAULT_DIGEST_METHOD_NOT_SET**<br><br>0x80510047 | The default digest method has not been set; to set it, call [IOpcSigningOptions::SetDefaultDigestMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setdefaultdigestmethod). |
| **OPC_E_DS_DIGEST_VALUE_ERROR**<br><br>0x8051001A | Cannot get the digest value of a package component or an element in the signature markup that was referenced for signing. |
| **OPC_E_DS_INVALID_OPC_SIGNATURE_TIME_FORMAT**<br><br>0x80510024 | The signature's time format is not a valid [OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format) enumeration value. |
| **OPC_E_DS_INVALID_RELATIONSHIPS_SIGNING_OPTION**<br><br>0x80510023 | An indicated relationship signing option is not a valid [OPC_RELATIONSHIPS_SIGNING_OPTION](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_relationships_signing_option) enumeration value. |
| **OPC_E_DS_SIGNATURE_CORRUPT**<br><br>0x80510019 | A signature in the package is not properly formed. Cannot get the signature value. |
| **OPC_E_DS_SIGNATURE_METHOD_NOT_SET**<br><br>0x80510046 | The signature method has not been set. Call [IOpcSigningOptions::SetSignatureMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setsignaturemethod) to set the signature method. |
| **OPC_E_NO_SUCH_PART**<br><br>0x80510018 | The specified part does not exist. |
| **Cryptography error** | An **HRESULT** error code from a [Cryptography](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-return-values) API. |
| **Windows Web Services error** | An **HRESULT** error code from a [Windows Web Services](https://learn.microsoft.com/windows/desktop/wsw/portal) API. |

## Remarks

This method uses Packaging objects to make changes to a package. The resultant changes are not saved until the package itself is saved.

 Before this method is called to generate a signature, call the [IOpcSigningOptions::SetDefaultDigestMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setdefaultdigestmethod) and [IOpcSigningOptions::SetSignatureMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-setsignaturemethod) methods.

To create an [IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions) interface pointer, which is required by this method, call the [CreateSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignaturemanager-createsigningoptions) method.

**Important** If the package is modified while this method is being executed, **Sign** may fail or generate an inconsistent signature. To avoid corruption of the package, use the APIs to save the package prior to calling **Sign**. For information about how to save a package, see [Saving a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/saving-a-package).

This method may create the following parts and relationships:

* The Digital Signature Origin part
* The package relationship of the digital signature origin relationship type
* One signature part that contains signature markup
* One or more part that contains a certificate
* One relationship that targets a signature part and that has the Digital Signature Origin part as its source
* One or more relationship that targets a signature part that contains a certificate and that has another signature part as its source

If **Sign** fails, any of the above parts and relationships may be represented, in the package, by Packaging objects. If the method returns the **OPC_E_DS_SIGNATURE_METHOD_NOT_SET** or **OPC_E_DS_DEFAULT_DIGEST_METHOD_NOT_SET** error code, the package has not been altered.

If **Sign** is successful, digest values are calculated for signed entities, and the generated signature is serialized as signature markup. Possible signed entities include the **Signature** element, references, parts, relationships, and package-specific and application-specific **Object** elements.

Errors that are introduced into a package signature when the caller is using the [IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions) interface to set signature information may not be exposed until **Sign** is called.

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

[Saving a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/saving-a-package)