# IWbemProviderInit::Initialize

## Description

The
**IWbemProviderInit::Initialize** method is called by Windows Management to initialize a provider to receive client requests. All types of providers must implement this method.

## Parameters

### `wszUser` [in]

A pointer to the user name, if per-user initialization was requested in the
[__Win32Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/--win32provider) registration instance for this provider. Otherwise, this is **NULL**.

Be aware that this parameter is set to **NULL** for event consumer providers regardless of the value of the **PerUserInitialization** property in the [__Win32Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/--win32provider) instance for the provider.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `wszNamespace` [in]

A namespace name for which the provider is initialized.

### `wszLocale` [in]

Locale name for which the provider is being initialized.

A string of the following format, where the hex value is a Microsoft standard LCID value:

* "MS_409"

This parameter may be **NULL**.

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management. This pointer is can service any requests made by the provider. The provider should use the [IWbemProviderInit::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on this pointer if it is going to call back into Windows Management during its execution.

### `pCtx` [in]

An
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) pointer associated with initialization. This parameter may be **NULL**.

If the provider will perform requests back into Windows Management before completing initialization, it should use the [IWbemProviderInit::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on this pointer. For more information, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

In the event that a provider must make a dependent request on another provider, you must pass this context string back to WMI to avoid potential lockups. However, in the case of an independent request, this is not necessary, and WMI generates a new context string for it.

### `pInitSink` [in]

An
[IWbemProviderInitSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemproviderinitsink) pointer that is used by the provider to report initialization status.

## Return value

The provider should return **WBEM_S_NO_ERROR** and indicate its status using the supplied object sink in the *pInitSink* parameter. However, if a provider returns **WBEM_E_FAILED** and does not use the sink, then the provider initialization is considered as failed.

## Remarks

Typically, the provider implements a COM object using multiple inheritance to support both the
[IWbemProviderInit](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemproviderinit) interface as well as its primary interface, such as
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) or
[IWbemEventProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventprovider).

Initialization status is reported by calling
[IWbemProviderInitSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemproviderinitsink-setstatus). This method can be called repeatedly to report incremental status if necessary. The provider must increment the reference count on this pointer by calling its [IWbemProviderInit::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method before using it to communicate status to Windows Management.

The provider may use the
[IWbemProviderInitSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemproviderinitsink) pointer synchronously, as in the following code example.

```cpp
HRESULT SampleProvider::Initialize(
    /* [unique][in] */  LPWSTR wszUser,
    /* [in] */          LONG lFlags,
    /* [in] */          LPWSTR wszNamespace,
    /* [unique][in] */  LPWSTR wszLocale,
    /* [in] */          IWbemServices __RPC_FAR *pNamespace,
    /* [in] */          IWbemContext __RPC_FAR *pCtx,
    /* [in] */          IWbemProviderInitSink __RPC_FAR *pInitSink
    )
{
    // Use AddRef on the pNamespace pointer, if required.

    // Analyze other parameters.

    // Tell Windows Management that you are initialized.
    pInitSink->SetStatus(WBEM_S_INITIALIZED, 0);
    return WBEM_S_NO_ERROR;
}
```

The provider may also use the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the pointer and create a separate thread to complete its initialization and immediately return from the call.

The initialization process of some providers can involve calling back into WMI. A provider that calls back into WMI and must wait for that call to complete is called a dependent provider. Similarly, a call into WMI is called a dependent request. When implementing
**Initialize**, WMI requires that a dependent provider obey the following rules:

* Dependent requests must reuse the
  [IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) pointer that WMI passed to
  **Initialize**.

  This means that any calls into WMI made during initialization must reuse the
  [IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) pointer that WMI passed in. Failure to do so can result in deadlock.
* Non-dependent requests must not reuse the
  [IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) pointer.
* Dependent providers must make requests to WMI by using one of the following two strategies:

  1. Make dependent requests with the thread received from WMI.
  2. Make dependent requests with a new thread created by the provider.
* All providers must return the thread received from WMI.
* Under no circumstances does WMI allow a provider to block a thread received from WMI.

  The danger in not carefully handling the threads delivered by WMI is that a provider may acquire all the threads in the WMI thread pool and proceed to block those threads. This would result in a deadlocked system.

You may choose to implement your provider in-process. An in-process provider that must connect to WMI separately from the initialization process must use the **CLSID_WbemAdministrativeLocator** class identifier to access
[IWbemLocator](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemlocator) in a call to [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).

The following code example describes how to use the **CLSID_WbemAdministrativeLocator** identifier in such a call.

```cpp
  IWbemLocator *pLoc = 0;

  DWORD dwRes = CoCreateInstance(CLSID_WbemAdministrativeLocator, 0,
      CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *) &pLoc);
```

Failure to use the **CLSID_WbemAdministrativeLocator** identifier results in an Access Denied error. For more information about making a connection to WMI, see
[Creating a WMI Application or Script](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-wmi-application-or-script).

#### Examples

The following code example describes how to implement
**Initialize** for an event consumer provider.

```cpp
HRESULT CMyEventConsumer::Initialize(
    /* [in] */ LPWSTR pszUser,
    /* [in] */ LONG lFlags,
    /* [in] */ LPWSTR pszNamespace,
    /* [in] */ LPWSTR pszLocale,
    /* [in] */ IWbemServices __RPC_FAR *pNamespace,
    /* [in] */ IWbemContext __RPC_FAR *pCtx,
    /* [in] */ IWbemProviderInitSink __RPC_FAR *pInitSink
    )
{
    pInitSink->SetStatus(WBEM_S_INITIALIZED, 0);

// Optionally, examine the namespace, locale, and so on
// being used.

    return WBEM_S_NO_ERROR;
}
```

## See also

[IWbemProviderInit](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemproviderinit)

[Initializing a Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/initializing-a-provider)