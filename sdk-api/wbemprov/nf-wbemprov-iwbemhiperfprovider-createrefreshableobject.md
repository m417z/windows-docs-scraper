# IWbemHiPerfProvider::CreateRefreshableObject

## Description

The
**IWbemHiPerfProvider::CreateRefreshableObject** method requests a refreshable instance object. The WMI Refresher calls **IWbemHiPerfProvider::CreateRefreshableObject** in response to a client request to the
[IWbemConfigureRefresher::AddObjectByPath](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addobjectbypath) or
[IWbemConfigureRefresher::AddObjectByTemplate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-addobjectbytemplate) interfaces. The provider reads the key from the supplied template object and supplies an object in the *ppRefreshable* parameter that will be refreshed whenever the refresh method on *pRefresher* is called. The provider associates the refreshable object with the supplied refresher, obtained from an earlier call to
[IWbemHiPerfProvider::CreateRefresher](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefresher).

**Note** If a provider does not implement this method, it must return **WBEM_E_PROVIDER_NOT_CAPABLE**.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any request made by the provider. If the pointer must call back into WMI during its execution, the provider calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on it.

### `pTemplate` [in]

Pointer to a
[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess) object that contains the template.

### `pRefresher` [in]

Pointer to a
[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher) object that contains a refresher obtained by calling
[IWbemHiPerfProvider::CreateRefresher](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefresher).

### `lFlags` [in]

Reserved. This parameter must be 0.

### `pContext` [in]

Typically **NULL**; otherwise, a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that is required by one or more dynamic class providers. The values in the context object must be specified in the specific provider documentation. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppRefreshable` [out]

Pointer that holds the reference to a
[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess) object, which will contain the refreshable object.

### `plId` [out]

Pointer to an integer returned by the provider that uniquely identifies this refreshable object.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The supplied instance template will contain an object with the key properties filled out. The returned object should be a unique, refreshable object. The provider must not touch the refreshable object except during a refresh operation. Your provider must not access the returned object, unless the object owning the refresher restores the object. The key properties of the supplied instance template will be filled out. The provider should also validate the instance path.

#### Examples

The following code example describes how to implement
**CreateRefreshableObject**.

```cpp
HRESULT CMyHiPerfProvider::CreateRefreshableObject(
  /* [in] */IWbemServices *pNamespace,
  /* [in] */IWbemObjectAccess *pTemplate,
  /* [in] */IWbemRefresher *pRefresher,
  /* [in] */long lFlags,
  /* [in] */IWbemContext *pCtx,
  /* [out] */IWbemObjectAccess **ppRefreshable,
  /* [out] */ long *plId
)
{
  // Use a private interface defined
  // to talk with the refresher. You must define
  // the IMyRefresher interface.
  IMyRefresher* pMyRefr = NULL;

  HRESULT hres = pRefresher->QueryInterface(
    IID_IMyRefresher,
    (void**) &pMyRefr );

  if ( SUCCEEDED( hres ) )
  {
    // Check for a valid instance.
    // You must implement the ValidateInst function.
    if ( ValidateInst( pTemplate ) )
    {
      IWbemClassObject* pTemplateObj = NULL;
      IWbemClassObject* pCloneObj = NULL;
      IWbemObjectAccess* pCloneAcc = NULL;

      // Clone the object, then get an
      // IWbemObjectAccess pointer.
      pTemplate->QueryInterface(
        IID_IWbemClassObject,
        (void**) &pTemplateObj );

      pTemplateObj->Clone( &pCloneObj );

      pCloneObj->QueryInterface(
        IID_IWbemObjectAccess,
        (void**) &pCloneAcc );

      // Generate a unique identifier.
      // For example, use:
      /**plId = InterlockedIncrement( &m_lLastId );*/

      // Add the object to an array of
      // objects to refresh.
      //For example, use:
      /*pMyRefr->AddInstance( *plId, pCloneAcc );*/

      // Maintains AddRef from QI
      *ppRefreshable = pCloneAcc;

      pTemplateObj->Release();
      pCloneObj->Release();
    }
    else
    {
      hres = WBEM_E_NOT_FOUND;
    }

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