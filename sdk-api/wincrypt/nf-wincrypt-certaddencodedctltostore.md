# CertAddEncodedCTLToStore function

## Description

The **CertAddEncodedCTLToStore** function creates a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from an encoded CTL and adds it to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The function makes a copy of the CTL context before adding it to the store.

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `dwMsgAndCertEncodingType` [in]

Specifies the type of encoding used. Both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) must be specified by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCtlEncoded` [in]

A pointer to a buffer containing the encoded CTL to be added to the certificate store.

### `cbCtlEncoded` [in]

The size, in bytes, of the *pbCtlEncoded* buffer.

### `dwAddDisposition` [in]

Specifies the action to take if a matching CTL or a link to a matching CTL already exists in the store. Currently defined disposition values and their uses are as follows

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | Makes no check for an existing matching CTL or link to a matching CTL. A new CTL is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching CTL or a link to a matching CTL exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching CTL or a link to a matching CTL exists, the **ThisUpdate** times on the CTLs are compared. If the existing CTL has a **ThisUpdate** time less than the **ThisUpdate** time on the new CTL, the old CTL or link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing CTL has a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CTL to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code. <br><br>If a matching CTL or a link to a matching CTL is not found in the store, a new CTL is added to the store. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | The action is the same as for CERT_STORE_ADD_NEWER, except that if an older CTL is replaced, the properties of the older CTL are incorporated into the replacement CTL. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a matching CTL or a link to a matching CTL exists, the existing CTL or link is deleted and a new CTL is created and added to the store. If a matching CTL or a link to a matching CTL does not exist, one is added. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching CTL exists in the store, that existing context is deleted before creating and adding the new context. The added context inherits properties from the existing CTL. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching CTL or a link to a matching CTL exists, that existing CTL is used and properties from the new CTL are added. The function does not fail, but no new CTL is added. If *ppCertContext* is not **NULL**, the existing context is duplicated. <br><br>If a matching CTL or a link to a matching CTL does not exist, a new CTL is added. |

### `ppCtlContext` [out, optional]

A pointer to a pointer to the decoded
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure. Can be **NULL** indicating that the calling application does not require a copy of the added or existing CTL. If a copy is made, it must be freed by using
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | CERT_STORE_ADD_NEW is set, and the CTL already exists in the store; or CERT_STORE_ADD_NEWER is set and there is a CTL in the store with a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CTL to be added. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter, or an encoding type that is not valid was specified. Currently, only the encoding types X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CertAddCTLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctlcontexttostore)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)