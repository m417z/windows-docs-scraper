# CryptUnregisterDefaultOIDFunction function

## Description

The **CryptUnregisterDefaultOIDFunction** removes the registration of a DLL containing the default function to be called for the specified encoding type and function name.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pszFuncName` [in]

Name of the function being unregistered.

### `pwszDll` [in]

Name of the DLL where the function is located.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)