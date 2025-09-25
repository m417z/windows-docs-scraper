# IX509PolicyServerListManager::Remove

## Description

The **Remove** method removes an [IX509PolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverurl) object from the collection by index number.

## Parameters

### `Index` [in]

A **LONG** variable that contains the index of the object to remove.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IX509PolicyServerListManager](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverlistmanager)