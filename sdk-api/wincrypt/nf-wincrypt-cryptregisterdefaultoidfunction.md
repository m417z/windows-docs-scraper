# CryptRegisterDefaultOIDFunction function

## Description

The **CryptRegisterDefaultOIDFunction** registers a DLL containing the default function to be called for the specified encoding type and function name. Unlike
[CryptRegisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidfunction), the function name to be exported by the DLL cannot be overridden.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pszFuncName` [in]

Name of the function being registered.

### `dwIndex` [in]

Index location for the insertion of the DLL in the list of DLLs. If *dwIndex* is zero, the DLL is inserted at the beginning of the list. If it is CRYPT_REGISTER_LAST_INDEX, the DLL is appended at the end of the list.

### `pwszDll` [in]

Optional environment-variable string to be expanded using [ExpandEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function before loading the DLL.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)