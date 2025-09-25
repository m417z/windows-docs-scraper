# IWbemConfigureRefresher::AddEnum

## Description

The
**IWbemConfigureRefresher::AddEnum** method adds an enumerator to the requested refresher.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any request made by the provider. If the method must call back into Windows Management during its execution, the provider should call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) with the *pNamespace* pointer.

### `wszClassName` [in]

Constant, null-terminated string of 16-bit Unicode characters containing the name of the class that is enumerated.

### `lFlags` [in]

Bitmask of flags that modify the behavior of this method. If this parameter is set to WBEM_FLAG_USE_AMENDED_QUALIFIERS, the returned instances contain localized qualifiers if they are available.

### `pContext` [in]

Typically **NULL**; otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that is required by one or more dynamic class providers. The values in the context object must be specified in the specific provider documentation. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppEnum` [out]

Pointer that holds the reference to a
[IWbemHiPerfEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemhiperfenum) object, which will contain the enumeration. The client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on this pointer when it is no longer required.

### `plId` [out]

Pointer to an integer returned by the provider that uniquely identifies the refreshable enumeration.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an

**Note** **HRESULT**

.

## Remarks

The supplied class must specify a valid class, which is provided by the High-Performance Provider. All instances of the returned enumerator can be queried after calls. On each call to refresh, the number of instances in the enumerator can vary. Only instances of the specified class name are returned; subclasses of the specified class will not be enumerated because detailed enumeration is not supported. The returned enumerator must not be touched by the client while a
[Refresh](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemrefresher-refresh) operation is in process. The returned identifier can be used by the
[Remove](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-remove) function to remove the object. Note that it is not necessary for the user to explicitly remove added enumerators. However, the client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned enumerator when it is no longer required.

## See also

[IWbemConfigureRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemconfigurerefresher)