# IWPCProviderState::Disable

## Description

Notifies the third-party application that it is not the current provider.

## Return value

If the method succeeds, the function returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method is called for every registered provider when the current provider changes. This means that the **Disable** method may be called for a provider that has already been disabled.

## See also

[IWPCProviderState](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcproviderstate)