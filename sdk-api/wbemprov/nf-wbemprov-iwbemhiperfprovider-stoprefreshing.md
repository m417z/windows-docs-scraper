# IWbemHiPerfProvider::StopRefreshing

## Description

The
**IWbemHiPerfProvider::StopRefreshing** method stops refreshing the object or enumerator corresponding to the supplied identifier. The WMI Refresher calls this method in response to a client request to [IWbemConfiguratorRefresher::Remove](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-remove). The provider should check the objects and enumerators associated with the refresher for a matching identifier. When the provider finds an identifier, the provider should remove or release the enumerator.

**Note** If a provider does not implement this method, it must return **WBEM_E_PROVIDER_NOT_CAPABLE**. A provider should implement **StopRefreshing** if it implements
[IWbemHiPerfProvider::CreateRefreshableEnum](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefreshableenum) or
[IWbemHiPerfProvider::CreateRefreshableObject](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefreshableobject).

## Parameters

### `pRefresher` [in]

A pointer to a
[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher) object that contains a refresher obtained by calling
[IWbemHiPerfProvider::CreateRefresher](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefresher).

### `lId` [in]

An integer containing a refresher identifier that uniquely identifies the object to stop refreshing.

### `lFlags` [in]

An integer containing the flags.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

It is not necessary to call
**StopRefreshing** to clean up a refresher. It is sufficient simply to delete the refresher; that is, to release all references to it. Deleting the refresher causes the cleanup of all objects and enumerators within it.

## See also

[Developing a WMI Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/developing-a-wmi-provider)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

Making an Instance Provider into a High-Performance Provider

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)

[Writing an Instance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)