# IWbemRefresher::Refresh

## Description

The
**IWbemRefresher::Refresh** method updates all refreshable objects, enumerators, and nested refreshers. The WMI Refresher calls this function in response to a client request to
**Refresh**.

## Parameters

### `lFlags` [in]

Bitmask of flags that modify the behavior of this method.

If **WBEM_FLAG_REFRESH_AUTO_RECONNECT** is specified and if the connection is broken, the refresher attempts to reconnect to the provider automatically. This is the default behavior for this method.

If you do not want the refresher to attempt to reconnect to the provider, specify **WBEM_FLAG_REFRESH_NO_AUTO_RECONNECT**.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

When refreshing enumerators and objects, providers should take as little time as possible. Using the
[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess) methods and caching property handles for reuse can dramatically improve performance. When updating enumerators, a provider can either remove and re-instantiate all objects, or simply remove and add the changed instances. It is up to you to choose the best approach. In either case, caching instances can improve performance.

The provider should only access the objects and enumerators in a refresher in response to a call to
**IWbemRefresher::Refresh**. It would, however, be perfectly valid to have a background thread polling for data with which to fill these objects, to prepare for when
**Refresh** is called.

#### Examples

The following code example describes how to implement
**Refresh**.

```cpp
HRESULT CMyHiPerfProviderRefresher::Refresh(
/* [in] */long lFlags
)
{
  // Run through all the objects and update their
  // data.

  // Now run through the enumerators.
  // Empty the enumerator and refill it.

  return WBEM_S_NO_ERROR;
}
```

## See also

[Developing a WMI Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/developing-a-wmi-provider)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher)

Making an Instance Provider into a High-Performance Provider

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)

[Writing an Instance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)