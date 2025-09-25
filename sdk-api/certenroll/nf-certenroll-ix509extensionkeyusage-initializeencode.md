# IX509ExtensionKeyUsage::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension by using the [X509KeyUsageFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyusageflags) enumeration. This method is web enabled.

## Parameters

### `UsageFlags` [in]

An [X509KeyUsageFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyusageflags) enumeration value. This can be a bitwise-**OR** combination of any of the following values.

| Value | Meaning |
| --- | --- |
| **XCN_CERT_DIGITAL_SIGNATURE_KEY_USAGE** | The key is used with a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) to support services other than nonrepudiation, certificate signing, or revocation list signing. DSAs are often used for authentication. |
| **XCN_CERT_NON_REPUDIATION_KEY_USAGE** | The key is used to verify a digital signature as part of a nonrepudiation service that protects against false denial of action by a signing entity. |
| **XCN_CERT_KEY_ENCIPHERMENT_KEY_USAGE** | The key is used for key transport. That is, the key is used to manage a key passed from its origination point to its point of actual use. |
| **XCN_CERT_DATA_ENCIPHERMENT_KEY_USAGE** | The key is used to encrypt user data other than cryptographic keys. |
| **XCN_CERT_KEY_AGREEMENT_KEY_USAGE** | The key is used for key agreement. The key agreement or key exchange protocol enables two or more parties to negotiate a key value without transferring the key and without previously establishing a shared secret. |
| **XCN_CERT_KEY_CERT_SIGN_KEY_USAGE** | The key is used to verify a certificate signature. This value can only be used for certificates issued by [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **XCN_CERT_OFFLINE_CRL_SIGN_KEY_USAGE** | The key is used to verify an offline [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) signature. |
| **XCN_CERT_CRL_SIGN_KEY_USAGE** | The key is used to verify a CRL signature. |
| **XCN_CERT_ENCIPHER_ONLY_KEY_USAGE** | The key is used to encrypt data while performing key agreement. The **XCN_CERT_KEY_AGREEMENT_KEY_USAGE** value must also be specified. |
| **XCN_CERT_DECIPHER_ONLY_KEY_USAGE** | The key is used to decrypt data while performing key agreement. The **XCN_CERT_KEY_AGREEMENT_KEY_USAGE** value must also be specified. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionkeyusage-initializedecode) before you can use an [IX509ExtensionKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionkeyusage) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the extension [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).
* The [KeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionkeyusage-get_keyusage) property retrieves the restrictions that identify the intended uses of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (the raw extension data).

## See also

[IX509ExtensionKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionkeyusage)