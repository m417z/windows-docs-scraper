# IWbemConfigureRefresher::Remove

## Description

The
**IWbemConfigureRefresher::Remove** method is used to remove an object, enumerator, or nested refresher from a refresher.

## Parameters

### `lId` [in]

Integer that uniquely identifies the object to remove. You obtain this identifier when you first add an object to the refresher by calling
[IWbemConfigureRefresher::AddObjectByPath](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addobjectbypath),
[IWbemConfigureRefresher::AddObjectByTemplate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addobjectbytemplate),
[IWbemConfigureRefresher::AddEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addenum), or
[IWbemConfigureRefresher::AddRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addrefresher).

### `lFlags` [in]

Bitmask of flags that modify the behavior of the
**Remove** method. If this parameter is set to. **WBEM_FLAG_REFRESH_AUTO_RECONNECT**, the refresher attempts to automatically reconnect to a remote provider if the connection is broken. This is default behavior for this method. Specify **WBEM_FLAG_REFRESH_NO_AUTO_RECONNECT** if you do not want the refresher to attempt to reconnect to a remote provider.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[Accessing Performance Data in C++](https://learn.microsoft.com/windows/desktop/WmiSdk/accessing-performance-data-in-c--)

[IWbemConfigureRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemconfigurerefresher)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

[Making an Instance Provider into a High-Performance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)