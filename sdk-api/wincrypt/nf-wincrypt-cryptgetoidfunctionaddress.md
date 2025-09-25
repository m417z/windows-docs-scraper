# CryptGetOIDFunctionAddress function

## Description

The **CryptGetOIDFunctionAddress** function searches the list of registered and installed functions for an encoding type and [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) match. If a match is found, the DLL that contains the function is, if necessary, loaded. If a match is found, a pointer to the function address and a pointer to the function handle are also returned. The [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on the function handle is incremented.

## Parameters

### `hFuncSet` [in]

The function set handle previously obtained from a call to
the [CryptInitOIDFunctionSet](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinitoidfunctionset) function.

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are used; however, additional encoding types can be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

For functions that do not use an encoding type, set this parameter to zero.

### `pszOID` [in]

If the high-order word of the OID is nonzero, *pszOID* is a pointer to either an OID string such as "2.5.29.1" or an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string such as "file". If the high-order word of the OID is zero, the low-order word specifies the numeric identifier to be used as the object identifier. This resulting OID maps to the function that was either installed or registered with the same OID.

### `dwFlags` [in]

This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **CRYPT_GET_INSTALLED_OID_FUNC_FLAG** | Searches only the installed list of functions. |

### `ppvFuncAddr` [out]

A pointer to a pointer to a function address. If a match is found, *ppvFuncAddr* points to the function address.

### `phFuncAddr` [out]

If a match is found, *phFuncAddr* points to the function handle. The [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the handle is incremented.
When you have finished using the handle, release the handle by calling the [CryptFreeOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfreeoidfunctionaddress) function.

**Note** By default, both the registered and installed function lists are searched. To search only the installed list of functions, set CRYPT_GET_INSTALLED_OID_FUNC_FLAG. This flag would be set by a registered function to get the address of a preinstalled function it was replacing. For example, the registered function might handle a new special case and call the preinstalled function to handle the remaining cases.

## Return value

If the function succeeds and a match is found, the function returns nonzero (**TRUE**).

If the function fails or no match is found, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can call **CryptGetOIDFunctionAddress** with the *pszOID* argument set to **CMSG_DEFAULT_INSTALLABLE_FUNC_OID** to get the default installable function for the following callback functions.

For retrieval of the default functions, set *dwEncodingType* to a bitwise **OR** combination of the following encoding types.

**CRYPT_ASN_ENCODING**
**X509_ASN_ENCODING**

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)