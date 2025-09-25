# SspiCompareAuthIdentities function

## Description

Compares the two specified credentials.

## Parameters

### `AuthIdentity1` [in]

A pointer to an opaque structure that specifies the first credential to compare.

### `AuthIdentity2` [in]

A pointer to an opaque structure that specifies the second credential to compare.

### `SameSuppliedUser` [out]

**TRUE** if the user account specified by the *AuthIdentity1* parameter is the same as the user account specified by the *AuthIdentity2* parameter; otherwise, **FALSE**.

### `SameSuppliedIdentity` [out]

**TRUE** if the identity specified by the *AuthIdentity1* parameter is the same as the identity specified by the *AuthIdentity2* parameter; otherwise, **FALSE**.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.