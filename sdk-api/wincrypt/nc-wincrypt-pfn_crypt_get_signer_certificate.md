# PFN_CRYPT_GET_SIGNER_CERTIFICATE callback function

## Description

The **CryptGetSignerCertificateCallback** user supplied callback function is used with the [CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure to get and verify a message signer's certificate.

## Parameters

### `pvGetArg` [in]

A pointer to user-defined data passed on to the verification function as specified in the [CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure.

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pSignerId` [in]

A pointer to a [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure containing the issuer and serial number. Can be **NULL** if there is no content or signer.

### `hMsgCertStore` [in]

A handle to the certificate store containing all the certificates and CRLs in the signed message.

## Return value

If a signer certificate is found, the function returns a pointer to a read-only [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context). The returned **CERT_CONTEXT** was obtained either from a certificate store or was created using [CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext). In either case, it must be freed using [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). If this function fails, the return value is **NULL**.

## Remarks

If the message does not contain content or signers, the function is called with *pSignerId* set to **NULL**.