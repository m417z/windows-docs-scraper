# ClusterDecrypt function

## Description

Decrypts [Checkpointing](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/checkpointing) data for a Cryptographic Service Provider (CSP).

## Parameters

### `hClusCryptProvider` [in]

A [HCLUSCRYPTPROVIDER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn823545(v=vs.85)) structure that contains a handle to the CSP.

### `pCryptInput` [in]

A pointer to the data to decrypt.

### `cbCryptInput` [in]

The total number of bytes in the data pointed to by the *pCryptInput* parameter.

### `ppCryptOutput` [out]

A pointer to a buffer that receives the decrypted data.

### `pcbCryptOutput` [out]

The total number of bytes in the data pointed to by the *ppCryptOutput* parameter.

## Return value

If the operation completes successfully, this function returns **ERROR_SUCCESS**; otherwise, it returns a system error code.

## See also

[Cryptography Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cryptography-functions)