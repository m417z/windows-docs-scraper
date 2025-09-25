# CryptXmlDllSignData callback function

## Description

The *CryptXmlDllSignData* function signs data.

The *CryptXmlDllSignData* function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `pSignatureMethod` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the algorithm.

### `hCryptProvOrNCryptKey` [in]

The handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) that creates the signature. This handle must be an **HCRYPTPROV** handle that was obtained from a call to the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function or an **NCRYPT_KEY_HANDLE** handle that was created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function. New applications should pass in an [NCRYPT_KEY_HANDLE](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov-or-ncrypt-key-handle) handle.

### `dwKeySpec` [in]

The private key to use from the provider's container. This key can be AT_KEYEXCHANGE or AT_SIGNATURE. This parameter is ignored if an **NCRYPT_KEY_HANDLE** handle is used in the *hCryptProvOrNCryptKey* parameter.

### `pbInput` [in]

A pointer to a buffer that contains the digest value to sign. The *cbInput* parameter contains the size of this buffer.

### `cbInput` [in]

The size, in bytes, of the buffer pointed to by the *pbInput* parameter.

### `pbOutput` [out, optional]

The address of a buffer to receive the signature produced by this function. The *cbOutput* parameter contains the size of this buffer.

If this parameter is **NULL**, this function will calculate the size needed for the encrypted data and return the size in the location pointed to by the *pcbResult* parameter.

### `cbOutput` [in]

The size, in bytes, of the buffer pointed to by the *pbOutput* parameter.

### `pcbResult` [out]

A pointer to a **DWORD** variable that receives the number of bytes copied to the *pbOutput* buffer.
If *pbOutput* is **NULL**, this receives the size, in bytes, required for the signature.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.