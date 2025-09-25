# CryptRegisterOIDFunction function

## Description

The **CryptRegisterOIDFunction** function registers a DLL that contains the function to be called for the specified encoding type, function name, and [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

By default, new function names are installed at the end of the list. To register a new function before the installed functions, call
the [CryptSetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetoidfunctionvalue) function with *dwValueType* set to **REG_DWORD** and *pwszValueName* set to CRYPT_OID_REG_FLAGS_VALUE_NAME.

CRYPT_OID_REG_FLAGS_VALUE_NAME is defined as L"CryptFlags".

In addition to registering a DLL, the name of the function to be called can be overridden. For example, the *pszFuncName* parameter can be set to CryptDllEncodeObject and the *pszOverrideFuncName* parameter to MyEncodeXyz. The new form of CryptDllEncodeObject can then be referred to by using the name MyEncodeXyz. This allows a DLL to export multiple OID functions for the same function name without needing to interpose its own OID dispatcher function.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pszFuncName` [in]

Name of the function being registered.

### `pszOID` [in]

OID of the function to be registered. If the high-order word of the OID is nonzero, *pszOID* is a pointer to either an OID string such as "2.5.29.1" or an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string such as "file." If the high-order word of the OID is zero, the low-order word specifies the numeric identifier to be used as the object identifier.

### `pwszDll` [in]

Name of the DLL file to be registered. It can contain environment-variable strings to be expanded by using the [ExpandEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function before loading the DLL.

### `pszOverrideFuncName` [in]

String that specifies a name for the function exported in the DLL. If *pszOverrideFuncName* is **NULL**, the function name specified by *pszFuncName* is used.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## Remarks

When you have finished using an OID function, unregister it by calling the [CryptUnregisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidfunction) function.

## See also

[CryptSetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetoidfunctionvalue)

[CryptUnregisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptunregisteroidfunction)

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)