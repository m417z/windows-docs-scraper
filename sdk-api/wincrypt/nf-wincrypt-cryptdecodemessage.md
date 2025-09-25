# CryptDecodeMessage function

## Description

The **CryptDecodeMessage** function decodes, decrypts, and verifies a cryptographic message.

This function can be used when the type of cryptographic message is unknown. The *dwMsgTypeFlags* constants can be combined with a bitwise-**OR** operation so that the function will try to find one of the types. When one of the types is found, the function reports the type found and returns the data appropriate to that type.

In each pass, the function cracks only a single level of encryption or encoding. For additional cracking, this function, or one of the other
[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions), must be called again.

## Parameters

### `dwMsgTypeFlags` [in]

Indicates the message type. Message types can be combined with the bitwise-**OR** operator. This parameter can be one of the following message types:

* CMSG_DATA_FLAG
* CMSG_SIGNED_FLAG
* CMSG_ENVELOPED_FLAG
* CMSG_SIGNED_AND_ENVELOPED_FLAG
* CMSG_HASHED_FLAG

**Note** After return, the **DWORD** pointed to by *pdwMsgType* is set with the type of the message.

### `pDecryptPara` [in]

A pointer to a
[CRYPT_DECRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_decrypt_message_para) structure that contains decryption parameters.

### `pVerifyPara` [in]

A pointer to a
[CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure that contains verification parameters.

### `dwSignerIndex` [in]

Indicates which signer, among the possible many signers of a message, is to be verified. This index can be changed in multiple calls to the function to verify additional signers.

*dwSignerIndex* is set to zero for the first signer. If the function returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns CRYPT_E_NO_SIGNER, the previous call returned the last signer of the message. This parameter is used only with messages of types CMSG_SIGNED_AND_ENVELOPED or CMSG_SIGNED. For all other message types, it should be set to zero.

### `pbEncodedBlob` [in]

A pointer to the encoded [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that is to be decoded.

### `cbEncodedBlob` [in]

The size, in bytes, of the encoded BLOB.

### `dwPrevInnerContentType` [in]

Only applicable when processing nested cryptographic messages. When processing an outer cryptographic message, it must be set to zero. When decoding a nested cryptographic message, it is set to the value returned at *pdwInnerContentType* by a previous calling of
**CryptDecodeMessage** for the outer message. It can be any of the CMSG types listed in *pdwMsgType*. For backward compatibility, set *dwPrevInnerContentType* to zero.

### `pdwMsgType` [out, optional]

A pointer to a **DWORD** that specifies the message type returned. This parameter can be one of the following message types:

* CMSG_DATA
* CMSG_SIGNED
* CMSG_ENVELOPED
* CMSG_SIGNED_AND_ENVELOPED
* CMSG_HASHED

### `pdwInnerContentType` [out, optional]

A pointer to a **DWORD** that specifies the type of an inner message. The message type codes used for *pdwMsgType* are used here, also.

If there is no cryptographic nesting, CMSG_DATA is returned.

### `pbDecoded` [out, optional]

A pointer to a buffer to receive the decoded message.

This parameter can be **NULL** if the decoded message is not required or to set the size of the decoded message for memory allocation purposes. A decoded message will not be returned if this parameter is **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbDecoded` [in, out, optional]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pbDecoded* parameter. When the function returns, this variable contains the size of the decoded message.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

### `ppXchgCert` [out, optional]

A pointer to a
pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure with a certificate that corresponds to the private [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) needed to decode the message. This parameter is only set for message types CMSG_ENVELOPED and CMSG_SIGNED_AND_ENVELOPED.

### `ppSignerCert` [out, optional]

A pointer to a
pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure of the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of the signer. This parameter is only set for message types CMSG_SIGNED and CMSG_SIGNED_AND_ENVELOPED.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The [CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage),
[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature), or
[CryptVerifyMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagehash) functions can be propagated to this function.

The following error code is most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbDecoded* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbDecoded*. |

## Remarks

The *dwMsgTypeFlags* parameter specifies the set of allowable messages. For example, to decode either SIGNED or ENVELOPED messages, set *dwMsgTypeFlags* to CMSG_SIGNED_FLAG | CMSG_ENVELOPED_FLAG. Either or both of the *pDecryptPara* or *pVerifyPara* parameters must be specified.

For a successfully decoded or verified message, the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) pointers pointed to by *ppXchgCert* and *ppSignerCert* are updated. They must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). If the function fails, they are set to **NULL**.

The *ppXchgCert* or *ppSignerCert* parameters can be set to **NULL** before the function is called, which indicates that the caller is not interested in getting the exchange certificate or the signer [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## See also

[CryptDecryptMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptmessage)

[CryptVerifyMessageHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagehash)

[CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)