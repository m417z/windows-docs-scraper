# PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC callback function

## Description

The **PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC** callback function is called by [CryptImportPublicKeyInfoEx2](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex2) to decode the [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) identifier, load the algorithm provider, and import the [key pair](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly).

## Parameters

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encrypt the subject. The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `pInfo` [in]

A pointer to a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information to import into the provider.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero.

### `pvAuxInfo` [in]

This parameter is reserved for future use and must be set to **NULL**.

### `phKey` [out]

A pointer to a **BCRYPT_KEY_HANDLE** variable that receives the handle of the imported key.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC | "CryptDllImportPublicKeyInfoEx2" |