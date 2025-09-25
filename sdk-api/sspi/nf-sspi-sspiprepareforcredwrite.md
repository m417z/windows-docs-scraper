# SspiPrepareForCredWrite function

## Description

Generates values from an identity structure that can be passed as the values of parameters in a call to the [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) function.

## Parameters

### `AuthIdentity` [in]

The identity structure from which to generate the credentials to be passed to the [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) function.

### `pszTargetName` [in]

A target name that can be modified by this function depending on the value of the *AuthIdentity* parameter.

Set the value of this parameter to **NULL** to use the user name as the target.

### `pCredmanCredentialType` [out]

The credential type to pass to the [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) function.

### `ppszCredmanTargetName` [out]

The target name to pass to the [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) function.

### `ppszCredmanUserName` [out]

The user name to pass to the [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) function.

### `ppCredentialBlob` [out]

The credential [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) to send to the [CredWrite](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritea) function.

### `pCredentialBlobSize` [out]

The size, in bytes, of the *ppCredentialBlob* buffer.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.