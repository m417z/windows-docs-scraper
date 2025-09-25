# CRYPT_VERIFY_MESSAGE_PARA structure

## Description

The **CRYPT_VERIFY_MESSAGE_PARA** structure contains information needed to verify signed messages.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwMsgAndCertEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be used to verify a signed message. The CSP identified by this handle is used for [hashing](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) and for signature verification.Unless there is a strong reason for using a specific cryptographic provider, set to zero to use the default RSA or DSS provider.

This member's data type is **HCRYPTPROV**.

### `pfnGetSignerCertificate`

A pointer to the callback function used to get the signer's certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). If **NULL**, the default callback is used. The default callback tries to get the signer [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from the message's [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

An application defined–callback function that gets the signer's certificate can be used in place of the default. It is passed the certificate identifier of the signer (its issuer and serial number) and a handle to its cryptographic signed message's certificate store.

See [CryptGetSignerCertificateCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_get_signer_certificate) for the callback functions signature and arguments.

### `pvGetArg`

Argument to pass to the callback function. Typically, this gets and verifies the message signer's certificate.

### `pStrongSignPara`

Optional pointer to a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure that contains parameters used for strong signing. If you set this member and the function successfully verifies the signature, the function will then check for a strong signature. If the signature is not strong, the operation will fail and set the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) value to **NTE_BAD_ALGID**.

**Note** You can use the **pStrongSignPara** member only if **CRYPT_VERIFY_MESSAGE_PARA_HAS_EXTRA_FIELDS** is defined by using the **#define** directive before including Wincrypt.h. If **CRYPT_VERIFY_MESSAGE_PARA_HAS_EXTRA_FIELDS** is defined, you must zero all unused fields.

**Windows 8 and Windows Server 2012:** Support for this member begins.

## Remarks

This structure is passed to the following functions:

* [CryptDecodeMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodemessage)
* [CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)
* [CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature)
* [CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)

[CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature)

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)