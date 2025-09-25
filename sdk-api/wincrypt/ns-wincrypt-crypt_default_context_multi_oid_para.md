# CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA structure

## Description

The **CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA** structure is used with the [CryptInstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalldefaultcontext) function to contain an array of object identifier strings.

## Members

### `cOID`

The number of elements in the **rgpszOID** array.

### `rgpszOID`

An array of pointers to null-terminated ANSI strings that contain the object identifier strings of the certificate signature algorithm to install the default provider for, for example, **szOID_OIWSEC_md5RSA**. The **cOID** member of this structure contains the number of elements in this array.

## See also

[CryptInstallDefaultContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalldefaultcontext)