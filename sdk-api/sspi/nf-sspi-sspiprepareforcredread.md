# SspiPrepareForCredRead function

## Description

Generates a target name and credential type from the specified identity structure.

The values that this function generates can be passed as the values of the *TargetName* and *Type* parameters in a call to the [CredRead](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreada) function.

## Parameters

### `AuthIdentity` [in]

The identity structure from which to generate the credentials to be passed to the [CredRead](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreada) function.

### `pszTargetName` [in]

A target name that can be modified by this function depending on the value of the *AuthIdentity* parameter.

### `pCredmanCredentialType` [out]

The credential type to pass to the [CredRead](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreada) function.

### `ppszCredmanTargetName` [out]

The target name to pass to the [CredRead](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreada) function.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.