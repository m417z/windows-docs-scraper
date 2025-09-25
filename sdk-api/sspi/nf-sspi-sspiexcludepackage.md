# SspiExcludePackage function

## Description

Creates a new identity structure that is a copy of the specified identity structure modified to exclude the specified [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

## Parameters

### `AuthIdentity` [in]

The identity structure to modify.

### `pszPackageName` [in]

The SSP to exclude.

### `ppNewAuthIdentity` [out]

The modified identity structure.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.