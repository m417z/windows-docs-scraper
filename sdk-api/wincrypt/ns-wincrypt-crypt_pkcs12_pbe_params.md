# CRYPT_PKCS12_PBE_PARAMS structure

## Description

The **CRYPT_PKCS12_PBE_PARAMS** structure contains parameters used to create an encryption key, [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) (IV), or [Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MAC) key for a [PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) password based encryption algorithm.

## Members

### `iIterations`

An integer that specifies the number of hashes of the password and salt that are used to create the key.

### `cbSalt`

An integer that specifies the size, in bytes, of the salt used to create the key.

## Remarks

The buffer that contains the salt immediately follows the **CRYPT_PKCS12_PBE_PARAMS** structure.

The [NCryptExportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptexportkey) and [NCryptImportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptimportkey) functions consume the **CRYPT_PKCS12_PBE_PARAMS** structure as an [NCryptBuffer](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbuffer) structure in the *pParameterList* parameter.

The [PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) standard recommends a value of 1024 or greater for the **iIterations** member.