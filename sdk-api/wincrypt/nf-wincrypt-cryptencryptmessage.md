# CryptEncryptMessage function

## Description

The **CryptEncryptMessage** function [encrypts](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) and [encodes](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) a message.

## Parameters

### `pEncryptPara` [in]

A pointer to a
[CRYPT_ENCRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encrypt_message_para) structure that contains the encryption parameters.

The **CryptEncryptMessage** function does not support the SHA2 OIDs, **szOID_DH_SINGLE_PASS_STDDH_SHA256_KDF** and **szOID_DH_SINGLE_PASS_STDDH_SHA384_KDF**.

### `cRecipientCert` [in]

Number of elements in the *rgpRecipientCert* array.

### `rgpRecipientCert` [in]

Array of pointers to
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures that contain the certificates of intended recipients of the message.

### `pbToBeEncrypted` [in]

A pointer to a buffer that contains the message that is to be encrypted.

### `cbToBeEncrypted` [in]

The size, in bytes, of the message that is to be encrypted.

### `pbEncryptedBlob` [out]

A pointer to [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains a buffer that receives the encrypted and encoded message.

To set the size of this information for memory allocation purposes, this parameter can be **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbEncryptedBlob` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbEncryptedBlob* parameter. When the function returns, this variable contains the size, in bytes, of the encrypted and encoded message copied to *pbEncryptedBlob*.

**Note** When processing the data returned in the buffer of the *pbEncryptedBlob*, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from calls to
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey),
[CryptEncrypt](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencrypt),
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey), and
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) can be propagated to this function.

The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the following error codes most often.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbEncryptedBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbEncryptedBlob*. |
| **E_INVALIDARG** | The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is not valid. Currently only PKCS_7_ASN_ENCODING is supported. The **cbSize** in **pEncryptPara* is not valid. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)