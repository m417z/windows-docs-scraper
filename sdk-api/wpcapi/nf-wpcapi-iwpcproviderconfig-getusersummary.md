# IWPCProviderConfig::GetUserSummary

## Description

Retrieves the information for each user by using the Parental Controls Control Panel. This interface is implemented by third parties.

## Parameters

### `bstrSID` [in]

A string that contains the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the user whose settings you want to obtain.

### `pbstrUserSummary` [out]

A pointer to a string that contains the summary details for the user specified in the *bstrSID* parameter.

## Return value

If the method succeeds, the function returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The user summary string is used to display information under each user in the Parental Controls Control Panel.

## See also

[IWPCProviderConfig](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcproviderconfig)