# IWbemHiPerfProvider::CreateRefreshableEnum

## Description

The
**IWbemHiPerfProvider::CreateRefreshableEnum** method creates a new refreshable enumeration. The WMI Refresher calls this method in response to a client request to
[IWbemConfigureRefresher::AddEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addenum). The provider associates the supplied
[IWbemHiPerfEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemhiperfenum) object with the supplied refresher. On each call to the supplied refresher's
[Refresh](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemrefresher-refresh) method, the provider ensures that the enumerator contains a set of all the instances of the class listed in the *wszClass* parameter and that these instances contain updated information. One possible way to do this would be to keep an array of refreshable enumerators in the refresher.

**Note** If a provider does not implement this method, it must return **WBEM_E_PROVIDER_NOT_CAPABLE**.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any requests made by the provider. If *pNamespace* must call back into Windows Management during its execution, the provider calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this pointer.

### `wszClass` [in]

Constant, **null**-terminated string of 16-bit, Unicode characters that contains the name of the class, whose instances are refreshed in the *pHiPerfEnum*  parameter.

### `pRefresher` [in]

Pointer to a
[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher) object that contains a refresher obtained by calling
[IWbemHiPerfProvider::CreateRefresher](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefresher).

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pContext` [in]

Typically **NULL**; otherwise, a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object required by one or more dynamic class providers. The values in the context object must be specified in the specific provider's documentation. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pHiPerfEnum` [in]

Pointer to a
[IWbemHiPerfEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemhiperfenum) object that contains the high-performance enumeration.

### `plId` [out]

Pointer to an integer returned by the provider that uniquely identifies the refreshable enumeration.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The provider must not modify the refreshable enumerator except during a refresh operation. The enumeration is shallow, so all instances placed in the enumerator should be of the class specified by *wszClass*.

The provider must not access the enumerator unless WMI calls the
[IWbemRefresher::Refresh](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemrefresher-refresh) method of the owner. As with refreshable objects, the provider must not update the enumerator unless the object owning the enumerator refreshes the enumerator.

#### Examples

The following code example describes how to implement
**CreateRefreshableEnum**.

```cpp
HRESULT CHiPerfProvider::CreateRefreshableEnum(
  /* [in] */IWbemServices *pNamespace,
  /* [in] */LPCWSTR wszClass,
  /* [in] */IWbemRefresher *pRefresher,
  /* [in] */long lFlags,
  /* [in] */IWbemContext *pCtx,
  /* [in] */IWbemHiPerfEnum *pEnum,
  /* [out] */ long *plId
)
{
  // Use a private interface defined
  // to talk with the refresher.
  IMyRefresher* pMyRefr = NULL;

  HRESULT hres = pRefresher->QueryInterface(
    IID_IMyRefresher,
    (void**) &pMyRefr );

  if ( SUCCEEDED( hres ) )
  {
  LPLONG plLastId;
    // Generates a unique identifier
    *plId = InterlockedIncrement( &plLastId );

    // Use an internal method to add the
    // enumerator to an array.
    pMyRefr->AddEnum( wszClass, *plId, pEnum );

    pMyRefr->Release();
  }

  return hres;
}
```

## See also

[Developing a WMI Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/developing-a-wmi-provider)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

Making an Instance Provider into a High-Performance Provider

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)

[Writing an Instance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)