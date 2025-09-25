# SspiValidateAuthIdentity function

## Description

Indicates whether the specified identity structure is valid.

## Parameters

### `AuthData` [in]

The identity structure to test.

## Return value

If the function succeeds, it returns **SEC_E_OK**, which indicates that the identity structure specified by the *AuthData* parameter is valid.

If the function fails, it returns a nonzero error code that indicates that the identity structure specified by the *AuthData* parameter is not valid.