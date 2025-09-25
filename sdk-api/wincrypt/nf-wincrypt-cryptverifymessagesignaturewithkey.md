# CryptVerifyMessageSignatureWithKey function

## Description

The **CryptVerifyMessageSignatureWithKey** function verifies a signed message's signature by using specified public key information.

## Parameters

### `pVerifyPara` [in]

A pointer to a
[CRYPT_KEY_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_verify_message_para) structure that contains verification parameters.

### `pPublicKeyInfo` [in]

A pointer to a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the public key that is used to verify the signed
message. If **NULL**, the signature is not verified.

### `pbSignedBlob` [in]

A pointer to a buffer that contains the signed message.

### `cbSignedBlob` [in]

The size, in bytes, of the signed message buffer.

### `pbDecoded` [out]

A pointer to a buffer to receive the decoded message.

This parameter can be **NULL** if the decoded message is not needed for additional processing or to set the size of the message for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbDecoded` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the *pbDecoded* buffer. When the function returns, this **DWORD** contains the size, in bytes, of the decoded message. The decoded message will not be returned if this parameter is **NULL**.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table shows the error codes most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbDecoded* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, in the variable pointed to by *pcbDecoded*. |
| **E_INVALIDARG** | Invalid message and certificate encoding types. Currently only PKCS_7_ASN_ENCODING and X509_ASN_ENCODING_TYPE are supported. Invalid **cbSize** in **pVerifyPara*. |
| **CRYPT_E_UNEXPECTED_MSG_TYPE** | Not a signed cryptographic message. |
| **CRYPT_E_NO_SIGNER** | The message does not have any signers or a signer for the specified *dwSignerIndex*. |
| **NTE_BAD_ALGID** | The message was hashed and signed by using an unknown or unsupported algorithm. |
| **NTE_BAD_SIGNATURE** | The message's signature was not verified. |