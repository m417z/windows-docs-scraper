# CryptMsgGetAndVerifySigner function

## Description

The **CryptMsgGetAndVerifySigner** function verifies a cryptographic message's signature.

## Parameters

### `hCryptMsg` [in]

Handle of a cryptographic message.

### `cSignerStore` [in]

Number of stores in the *rghSignerStore* array.

### `rghSignerStore` [in, optional]

Array of certificate store handles that can be searched for a signer's certificate.

### `dwFlags` [in]

Indicates particular use of the function.

| Value | Meaning |
| --- | --- |
| **CMSG_TRUSTED_SIGNER_FLAG** | The stores in *rghSignerStore* are assumed trusted and they are the only stores searched to find the certificate corresponding to the signer's issuer and serial number. Otherwise, signer stores can be provided to supplement the message's store of certificates. If a signer certificate is found, its public key is used to verify the message signature. |
| **CMSG_SIGNER_ONLY_FLAG** | Return the signer without doing the signature verification. |
| **CMSG_USE_SIGNER_INDEX_FLAG** | Only the signer specified by **pdwSignerIndex* is returned. Otherwise, iterate through all the signers until a signature is verified or there are no more signers. |

### `ppSigner` [out, optional]

If the signature is verified, *ppSigner* is updated to point to the signer's [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). When you have finished using the certificate, free the context by calling the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function. This parameter can be **NULL** if the application has no need for the signer's certificate.

### `pdwSignerIndex` [in, out, optional]

If the signature is verified, *pdwSigner* is updated to point to the index of the signer in the array of signers. This parameter can be **NULL** if the application has no need for the index of the signer.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)

[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode)

[Verification Functions Using CTLs](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)