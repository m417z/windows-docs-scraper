# CryptInstallOIDFunctionAddress function

## Description

The **CryptInstallOIDFunctionAddress** function installs a set of callable [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) function addresses.

## Parameters

### `hModule` [in]

This parameter is updated with the *hModule* parameter passed to **DllMain** to prevent the DLL that contains the function addresses from being unloaded by
[CryptGetOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionaddress) or
[CryptFreeOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfreeoidfunctionaddress). This would be the case when the DLL has also registered OID functions through
[CryptRegisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidfunction).

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

### `pszFuncName` [in]

Name of the function set being installed.

### `cFuncEntry` [in]

Number of array elements in *rgFuncEntry*[].

### `rgFuncEntry` [in]

Array of [CRYPT_OID_FUNC_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_func_entry) structures, each containing an OID and the starting address of its correlated routine.

Default functions are installed by setting the **pszOID** member of the [CRYPT_OID_FUNC_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_func_entry) structure for their array element to CRYPT_DEFAULT_OID.

### `dwFlags` [in]

By default, a new function set is installed at the end of the list of function sets. Setting the CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG flag installs the function set at the beginning of the list.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## See also

[CRYPT_OID_FUNC_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_func_entry)

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)