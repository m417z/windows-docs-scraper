# IAzApplication3::ScopeExists

## Description

The **ScopeExists** method indicates whether the specified scope exists in this [IAzApplication3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication3) object.

## Parameters

### `bstrScopeName` [in]

A string that contains the name of the scope to be checked.

### `pbExist` [out]

**VARIANT_TRUE** if the specified scope exists in this [IAzApplication3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication3) object; otherwise, **VARIANT_FALSE**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).