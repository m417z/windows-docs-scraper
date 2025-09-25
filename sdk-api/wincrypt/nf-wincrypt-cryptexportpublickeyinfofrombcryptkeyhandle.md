# CryptExportPublicKeyInfoFromBCryptKeyHandle function

## Description

The **CryptExportPublicKeyInfoFromBCryptKeyHandle** function exports the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information associated with a provider's corresponding [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `hBCryptKey` [in]

The handle of the key from which to export the public key information.

### `dwCertEncodingType` [in]

Specifies the encoding type to be matched.

This value can be a bitwise combination of the currently defined encoding types:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pszPublicKeyObjId` [in, optional]

A pointer to the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that identifies the installable function to use to export the key. If the high-order word of the OID is nonzero, *pszPublicKeyObjId* is a pointer to either an OID string such as "2.5.29.1" or an ASCII string such as "file." If the high-order word of the OID is zero, the low-order word specifies the integer identifier to be used as the object identifier.

### `dwFlags` [in]

A **DWORD** value that indicates how the public key information is exported.

| Value | Meaning |
| --- | --- |
| **CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG**<br><br>0x80000000 | Skips public keys in the **CRYPT_PUBKEY_ALG_OID_GROUP_ID** group that are explicitly flagged with the **CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG** flag. |
| **CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG**<br><br>0x40000000 | Skips public keys in the **CRYPT_PUBKEY_ALG_OID_GROUP_ID** group that are explicitly flagged with the **CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG** flag. |

### `pvAuxInfo` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `pInfo` [out, optional]

A pointer to a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure to receive the public key information to be exported.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbInfo` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pInfo* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer.

## Return value

The function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

 If the **CryptExportPublicKeyInfoFromBCryptKeyHandle** function is unable to find an installable OID function for the OID specified by the *pszPublicKeyObjId* parameter, it attempts to export the key as a RSA Public Key (**szOID_RSA_RSA**).
If the key is exported as a RSA Public Key, the values of the *dwFlags* and *pvAuxInfo* parameters are not used.