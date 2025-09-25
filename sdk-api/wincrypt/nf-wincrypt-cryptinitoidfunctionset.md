# CryptInitOIDFunctionSet function

## Description

The **CryptInitOIDFunctionSet** initializes and returns the handle of the OID function set identified by a supplied function set name. If the set already exists, the handle of the existing set is returned. If the set does not exist, it is created. This allows different DLLs to install OID functions for the same function set name.

## Parameters

### `pszFuncName` [in]

Name of the OID function set.

### `dwFlags` [in]

Reserved for future use and must be zero.

## Return value

Returns the handle of the OID function set identified by *pszFuncName*, or **NULL** if the function fails.

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)