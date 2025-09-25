# ISmimeCapabilities::AddAvailableSmimeCapabilities

## Description

The **AddAvailableSmimeCapabilities** method adds [ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability) objects to the collection by identifying the encryption algorithms supported by the default RSA cryptographic provider.

## Parameters

### `MachineContext` [in]

A **VARIANT_BOOL** variable that identifies the certificate store context. Specify **VARIANT_TRUE** for the computer and **VARIANT_FALSE** for the user.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ISmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapabilities)

[ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability)