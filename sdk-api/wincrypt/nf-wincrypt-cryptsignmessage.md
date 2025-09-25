# CryptSignMessage function

## Description

The **CryptSignMessage** function creates a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the specified content, signs the hash, and then encodes both the original message content and the signed hash.

## Parameters

### `pSignPara` [in]

A pointer to
[CRYPT_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_sign_message_para) structure containing the signature parameters.

### `fDetachedSignature` [in]

**TRUE** if this is to be a detached signature. Otherwise, **FALSE**. If this parameter is set to **TRUE**, only the signed hash is encoded in *pbSignedBlob*. Otherwise, both *rgpbToBeSigned* and the signed hash are encoded.

### `cToBeSigned` [in]

Count of the number of array elements in *rgpbToBeSigned* and *rgcbToBeSigned*. This parameter must be set to one unless *fDetachedSignature* is set to **TRUE**.

### `rgpbToBeSigned` [in]

Array of pointers to buffers that contain the contents to be signed.

### `rgcbToBeSigned` [in]

Array of sizes, in bytes, of the content buffers pointed to in *rgpbToBeSigned*.

### `pbSignedBlob` [out]

A pointer to a buffer to receive the encoded signed hash, if *fDetachedSignature* is **TRUE**, or to both the encoded content and signed hash if *fDetachedSignature* is **FALSE**.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbSignedBlob` [in, out]

A pointer to a **DWORD** specifying the size, in bytes, of the *pbSignedBlob* buffer. When the function returns, this variable contains the size, in bytes, of the signed and encoded message.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following lists the error codes most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbSignedBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, into the variable pointed to by *pcbSignedBlob*. |
| **E_INVALIDARG** | The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is not valid. Currently only PKCS_7_ASN_ENCODING is supported. The **cbSize** in **pSignPara* is not valid. |
| **CRYPT_E_NO_KEY_PROPERTY** | The *pSigningCert* in **pSignPara* does not have a CERT_KEY_PROV_INFO_PROP_ID or CERT_KEY_CONTEXT_PROP_ID property. |

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata), and
[CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha) might be propagated to this function.

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptSignAndEncryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencryptmessage)

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)