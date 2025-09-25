# CryptSignMessageWithKey function

## Description

The **CryptSignMessageWithKey** function signs a message by using a CSP's private key specified in the
parameters. A placeholder **SignerId** is created and stored in the message.

## Parameters

### `pSignPara` [in]

A pointer to
a [CRYPT_KEY_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_sign_message_para) structure that contains the signature parameters.

### `pbToBeSigned` [in]

A pointer to a buffer array that contains the message to be signed.

### `cbToBeSigned` [in]

The number of array elements in the *pbToBeSigned* buffer array.

### `pbSignedBlob` [out]

A pointer to a buffer to receive the encoded signed message.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbSignedBlob` [in, out]

A pointer to a **DWORD** value that indicates the size, in bytes, of the *pbSignedBlob* buffer. When the function returns, this variable contains the size, in bytes, of the signed and encoded message.

**Note** When processing the data returned, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following lists the error codes most commonly returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbSignedBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, into the variable pointed to by *pcbSignedBlob*. |
| **E_INVALIDARG** | The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is not valid. Currently only PKCS_7_ASN_ENCODING is supported. The **cbSize** in **pSignPara* is not valid. |
| **CRYPT_E_NO_KEY_PROPERTY** | The *pSigningCert* in **pSignPara* does not have a CERT_KEY_PROV_INFO_PROP_ID or CERT_KEY_CONTEXT_PROP_ID property. |