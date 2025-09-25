# IWbemHiPerfProvider::CreateRefresher

## Description

The
**IWbemHiPerfProvider::CreateRefresher** method creates a refresher. The returned refresher will be used in subsequent calls to
[IWbemHiPerfProvider::CreateRefreshableEnum](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefreshableenum),
[IWbemHiPerfProvider::CreateRefreshableObject](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefreshableobject), and
[IWbemHiPerfProvider::StopRefreshing](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-stoprefreshing).

**Note** If a provider does not implement this method, it must return **WBEM_E_PROVIDER_NOT_CAPABLE**. A provider must implement this method to support refresher operations.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any request made by the provider. The provider should call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this pointer if it is going to call back into Windows Management during its execution.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `ppRefresher` [out]

Pointer to hold the reference to the provider's implementation of the
[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher) interface.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The provider must supply its own implementation of the
[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher) interface. It is valid for WMI to request multiple refreshers, each of which will be used for its own refresh operations.

When you release a refresher, the provider should clean up any refreshable objects or enumerators that were added to the refresher.

#### Examples

The following code example describes how to implement
**CreateRefresher**.

```cpp
HRESULT CHiPerfProvider::CreateRefresher(
  /* [in] */IWbemServices *pNamespace,
  /* [in] */ long lFlags,
  /* [out] */ IWbemRefresher** ppRefresher
)
{
    // Allocate a new refresher
    //For Example:
    // CMyRefresher* pMyRefresher = new CMyRefresher();

    // Return the refresher to the ppRefresher
    // [out] parameter
    /*return pMyRefresher->QueryInterface(
     IID_IWbemRefresher, (void**) ppRefresher );*/
}

// Free memory resources.
// For Example:
//pNamespace->Release();
//ppRefresher->Release();
//delete[] pMyRefresher;
```

## See also

[Developing a WMI Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/developing-a-wmi-provider)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

Making an Instance Provider into a High-Performance Provider

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)

[Writing an Instance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)