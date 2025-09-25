# CryptImportPublicKeyInfoEx2 function

## Description

The **CryptImportPublicKeyInfoEx2** function imports a public key into the CNG asymmetric provider that corresponds to the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and returns a CNG handle to the key.

## Parameters

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encrypt the subject. The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `pInfo` [in]

The address of a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the public key information to import into the provider.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG** | Skips public keys in the CRYPT_PUBKEY_ALG_OID_GROUP_ID group that are explicitly flagged with the CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG flag. |
| **CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG** | Skips public keys in the CRYPT_PUBKEY_ALG_OID_GROUP_ID group that are explicitly flagged with the CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG flag. |

These flags are passed in the *dwKeyType* parameter of the [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) function when mapping the public key object identifier to the corresponding CNG public key algorithm identifier.

### `pvAuxInfo` [in]

This parameter is reserved for future use and must be set to **NULL**.

### `phKey` [out]

The address of a **BCRYPT_KEY_HANDLE** variable that receives the handle of the imported key.

When this handle is no longer needed, you must release it by calling the [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | An import function that can be installed or registered could not be found for the specified *dwCertEncodingType* and *pInfo* parameters. |
| **E_INVALIDARG** | One or more parameters are not valid. |

## See also

[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info)