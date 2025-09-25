# IX509CertificateRequestPkcs7::InitializeFromCertificate

## Description

The **InitializeFromCertificate** method initializes the certificate request by using an existing certificate. The certificate is contained in a byte array encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) as defined by the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard. The DER-encoded byte array is represented by a string that is either a pure binary sequence or is Unicode encoded.

## Parameters

### `Context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies whether the requested certificate is intended for an end user, a computer, or an administrator acting on behalf of the computer.

### `RenewalRequest` [in]

A **VARIANT_BOOL** that indicates whether the end entity is requesting that the certificate identified by the *strCertificate* parameter be renewed.

### `strCertificate` [in]

A **BSTR** variable that contains the DER-encoded certificate.

Beginning with Windows 7 and Windows Server 2008 R2, you can specify a certificate thumb print or serial number rather than an encoded certificate. Doing so causes the function to search the appropriate local stores for the matching certificate. Keep in mind the following points:

* The **BSTR** must be an even number of hexadecimal digits.
* Whitespace between hexadecimal pairs is ignored.
* The *Encoding* parameter must be set to **XCN_CRYPT_STRING_HEXRAW**.
* The *Context* parameter determines whether the local or computer stores or both are searched.
* If a private key is needed, only the personal and request stores are searched.
* If a private key is not needed, the root and intermediate CA stores are also searched.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of encoding applied to the DER-encoded certificate. The default value is **XCN_CRYPT_STRING_BASE64**.

### `InheritOptions` [in]

An [X509RequestInheritOptions](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509requestinheritoptions) enumeration value that specifies how to create the certificate request object from the existing certificate. You can specify how to inherit a key by choosing one of the following values. The default value is **InheritDefault**.

| Value | Meaning |
| --- | --- |
| ****InheritDefault**** | Provider and key inheritance is not specified. |
| ****InheritNewDefaultKey**** | Creates a new key but inherits the default cryptographic provider. |
| ****InheritNewSimilarKey**** | Creates a new key but inherits the cryptographic provider used to create the existing certificate. |
| ****InheritPrivateKey**** | Inherits the private and public keys. |
| ****InheritPublicKey**** | Inherits only the public key. |

You can also use a bitwise-**AND** operation to combine the key inheritance value with any combination of the following values.

| Value | Meaning |
| --- | --- |
| ****InheritRenewalCertificateFlag**** | Inherits the renewal certificate. Specifying this flag sets an [ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal) value. |
| ****InheritTemplateFlag**** | Inherits the certificate template. |
| ****InheritSubjectFlag**** | Inherits the subject distinguished name. |
| ****InheritExtensionsFlag**** | Inherits the relevant extensions from the certificate. |
| ****InheritSubjectAltNameFlag**** | Inherits the **SubjectAlternativeName** extension. |
| ****InheritValidityPeriodFlag**** | Inherits the validity period. |

You can also specify **InheritNone** to prevent any of the flags in the preceding table (flags not related to key inheritance) from being implemented by default. If you specify **InheritNone** but also specify a flag not related to key inheritance, the method returns **E_INVALIDARG**.

If you set the *InheritOptions* parameter to zero (0) or specify **InheritDefault** and do not specify a key inheritance value, **InheritNewSimilarKey** is used by default.

If you set the *InheritOptions* parameter to zero (0) or specify **InheritDefault** and do not specify any of the values not related to key inheritance, the following flags are set by default:

* **InheritSubjectFlag**
* **InheritExtensionsFlag**
* **InheritValidityPeriodFlag**
* **InheritTemplateFlag** (if the certificate contains a template extension)
* **InheritRenewalCertificateFlag** (if the client is renewing a certificate)

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **ERROR_ALREADY_INITIALIZED** | The certificate request object has already been initialized. |

## Remarks

The **InitializeFromCertificate** method validates the options specified in the *InheritOptions* parameter and initializes a new PKCS #7 request object by performing the following actions:

* Creates a PKCS #10 request object from the certificate, enrollment context, and inherit options specified on input. The PKCS #10 object inherits:
  + The template if one exists in the original certificate and you set the **InheritTemplateFlag** value.
  + The subject distinguished name if you specify **InheritSubjectFlag**.
  + The subject alternative name if you specify **InheritSubjectAltNameFlag**.
  + The extensions if you specify **InheritExtensionsFlag**.
* Copies the original certificate, if it is to be renewed, to the [RenewalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_renewalcertificate) property on the new PKCS #10 request.
* Creates an [ISignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-isignercertificate) from the original certificate, if it is to be renewed, and sets it on the [SignerCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs7-get_signercertificate) property.
* Sets the PKCS #10 request as the inner request object.

## See also

[IX509CertificateRequestPkcs7](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs7)