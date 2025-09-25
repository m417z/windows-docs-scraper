# CryptGetDefaultOIDFunctionAddress function

## Description

The **CryptGetDefaultOIDFunctionAddress** function loads the DLL that contains a default function address. It can also return the address of the first or next installed default [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) function in an initialized function set and load the DLL that contains the address of that function.

## Parameters

### `hFuncSet` [in]

Function set handle previously obtained from a call to
[CryptInitOIDFunctionSet](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinitoidfunctionset).

### `dwEncodingType` [in]

Encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

### `pwszDll` [in, optional]

Name of the DLL to load. Normally, the DLL name is obtained from the list returned by
[CryptGetDefaultOIDDllList](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetdefaultoiddlllist). If *pwszDll* is **NULL**, a search is performed on the list of installed default functions.

### `dwFlags` [in]

Reserved for future use and must be zero.

### `ppvFuncAddr` [out]

A pointer to the address of the return function. If the function fails, a **NULL** is returned in *ppvFuncAddr*.

### `phFuncAddr` [in, out]

Used only if *pwszDll* is **NULL**. On the first call to the function, **phFuncAddr* must be **NULL** to acquire the first installed function.

When this function is successful, **phFuncAddr* is set to a function handle. The [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the function handle is incremented.

After the first call to the function, *phFuncAddr* is set to the pointer returned by the previous call. This input pointer is always freed within the function through a call to
[CryptFreeOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfreeoidfunctionaddress) by this function. The call to free the pointer is always made even when the main function returns an error.

A non-**NULL***phFuncAddr* must be released either through a call to [CryptFreeOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfreeoidfunctionaddress) or by being passed back as input to this function or as input to
[CryptGetOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionaddress).

If *pwszDll* is not **NULL**, the value of this parameter is ignored and a non-**NULL** pointer is not freed.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)