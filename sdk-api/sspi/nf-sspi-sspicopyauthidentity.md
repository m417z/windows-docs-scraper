# SspiCopyAuthIdentity function

## Description

Creates a copy of the specified opaque credential structure.

## Parameters

### `AuthData` [in]

The credential structure to be copied.

### `AuthDataCopy` [out]

The structure that receives the copy of the structure specified by the *AuthData* parameter.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.