# CertCreateCTLContext function

## Description

The **CertCreateCTLContext** function creates a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context from an encoded CTL. The created context is not persisted to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The function makes a copy of the encoded CTL within the created context.

## Parameters

### `dwMsgAndCertEncodingType` [in]

Specifies the type of encoding used. Both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) must be specified by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCtlEncoded` [in]

A pointer to a buffer containing the encoded CTL from which the context is to be created.

### `cbCtlEncoded` [in]

The size, in bytes, of the *pbCtlEncoded* buffer.

## Return value

If the function succeeds, the return value is a pointer to a read-only
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context).

If the function fails and is unable to decode and create the [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context), the return value is **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table shows a possible error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid certificate encoding type. Only PKCS_7_ASN_ENCODING and X509_ASN_ENCODING are supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

The
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) must be freed by calling
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).
[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext) can be called to make a duplicate.
[CertSetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetctlcontextproperty) and
[CertGetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetctlcontextproperty) can be called to store and read properties for the CTL.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertCreateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecrlcontext)

[CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext)

[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[CertGetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetctlcontextproperty)

[CertSetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetctlcontextproperty)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)