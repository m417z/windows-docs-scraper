# IAzClientContext3::IsInRoleAssignment

## Description

The **IsInRoleAssignment** method checks whether the principal represented by the current client context is a member of the specified role in the specified scope.

## Parameters

### `bstrScopeName` [in]

The name of the scope to check.

### `bstrRoleName` [in]

The name of the role to check.

### `pbIsInRole` [out]

**VARIANT_TRUE** if the principal represented by the current client context is a member of the role specified by the *bstrRoleName* parameter in the scope specified by the *bstrScopeName* parameter; otherwise, **VARIANT_FALSE**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).