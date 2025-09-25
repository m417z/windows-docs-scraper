# IWbemConfigureRefresher::AddObjectByTemplate

## Description

With the
**IWbemConfigureRefresher::AddObjectByTemplate** method, you can add an object you want refreshed to a refresher by specifying an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) instance template. Use this method when it is difficult to construct an object path for an object to add to a refresher.

**Note** The key properties of the instance object must be filled out before you can call the
**AddObjectByTemplate** method.

## Parameters

### `pNamespace`

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any request made by the provider. The provider should call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this pointer if it is going to call back into Windows Management during its execution.

### `pTemplate` [in]

Pointer to a
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object that contains the instance template.

### `lFlags` [in]

Bitmask of flags that modify the behavior of this method. If this parameter is set to **WBEM_FLAG_USE_AMENDED_QUALIFIERS**, the returned instance will contain localized qualifiers if available.

### `pContext` [in]

Typically **NULL**; otherwise, a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that is required by one or more dynamic class providers. The values in the context object must be specified in the specific provider documentation. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppRefreshable` [out]

Pointer to hold the reference to a
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object, which will contain the refreshable instance object. The client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned object when it is no longer required.

### `plId` [out]

Pointer to an integer returned by the provider that uniquely identifies this refreshable object.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The supplied instance must specify a valid object, which is provided by the High-Performance Provider. The returned object must not be modified by the client while a refresh operation is in process. The returned identifier can be used by the
[Remove](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-remove) function to remove the object.

It is not necessary for the user to explicitly remove added objects. The client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned object when it is no longer required.

## See also

[Accessing Performance Data in C++](https://learn.microsoft.com/windows/desktop/WmiSdk/accessing-performance-data-in-c--)

[IWbemConfigureRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemconfigurerefresher)

[Making an Instance Provider into a High-Performance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)