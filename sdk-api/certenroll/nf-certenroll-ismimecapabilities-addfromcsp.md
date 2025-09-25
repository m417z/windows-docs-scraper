# ISmimeCapabilities::AddFromCsp

## Description

The **AddFromCsp** method adds objects to the collection by identifying the encryption algorithms supported by a specific cryptographic provider.

## Parameters

### `pValue` [in]

Pointer to an [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface that represents the provider.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ISmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapabilities)

[ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability)