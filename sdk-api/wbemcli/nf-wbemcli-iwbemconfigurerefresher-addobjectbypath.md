# IWbemConfigureRefresher::AddObjectByPath

## Description

The
**IWbemConfigureRefresher::AddObjectByPath** method adds an object to a refresher by specifying an object path.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any request made by the provider. The provider should call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this pointer if it is going to call back into Windows Management during its execution.

### `wszPath` [in]

Constant, null-terminated string of 16-bit Unicode characters that contains the object path of the object you add to the refresher.

### `lFlags` [in]

Bitmask of flags that modify the behavior of this method. If this parameter is set to **WBEM_FLAG_USE_AMENDED_QUALIFIERS**, the returned instance contain localized qualifiers if available.

### `pContext` [in]

Typically **NULL**; otherwise, a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that is required by one or more dynamic class providers. The values in the context object must be specified in the specific provider documentation. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppRefreshable` [out]

Pointer to hold the reference to a
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object, which contains the refreshable instance object. The client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned object when it is no longer required.

### `plId` [out]

Pointer to an integer returned by the provider that uniquely identifies the refreshable object.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The supplied path must specify a valid object, which is provided by the High-Performance Provider. The returned object must not be touched by the client while a refresh operation is in process. The returned identifier can be used by the
[Remove](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-remove) function to remove the object.

**Note** It is not necessary for the user to explicitly remove added objects. The client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned object when it is no longer required.

## See also

[Accessing Performance Data in C++](https://learn.microsoft.com/windows/desktop/WmiSdk/accessing-performance-data-in-c--)

[IWbemConfigureRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemconfigurerefresher)

[Making an Instance Provider into a High-Performance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)