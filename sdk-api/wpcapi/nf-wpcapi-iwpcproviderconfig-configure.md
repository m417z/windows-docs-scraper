# IWPCProviderConfig::Configure

## Description

Called for the current provider when you click a user tile in the Parental Controls Control Panel. This method allows for changes to the configuration.

## Parameters

### `hWnd` [in]

A handle to the parent window.

### `bstrSID` [in]

A string that contains the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the user to configure.

## Return value

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Allows the provider to not handle the configuration user interface and instead to rely on the in-box Parental Controls configuration user interface. |

## See also

[IWPCProviderConfig](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcproviderconfig)