# IWbemProviderIdentity::SetRegistrationObject

## Description

The
**IWbemProviderIdentity::SetRegistrationObject** method is called by the Windows Management service prior to initializing an event provider (if the provider implements
[IWbemProviderIdentity](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemprovideridentity)). The method is used to pass to the provider the
[__Win32Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/--win32provider) instance by which the provider is being initialized. This method is only used if you have more than one provider sharing the same **CLSID**.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pProvReg` [in]

Instance of
[__Win32Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/--win32provider) that announces the provider's name and **CLSID**.

## Return value

This method returns an **HRESULT** with one of the following values.

## Remarks

Any **HRESULT** return code other than **WBEM_S_NO_ERROR** indicates a provider failure.

## See also

[IWbemProviderIdentity](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemprovideridentity)