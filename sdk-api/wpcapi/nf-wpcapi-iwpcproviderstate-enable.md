# IWPCProviderState::Enable

## Description

Notifies the third-party application that it has been selected as the new current provider.

## Return value

If the method succeeds, the function returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method is called when the current provider is changed through the drop-down list in the Parental Controls Control Panel.

## See also

[IWPCProviderState](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcproviderstate)