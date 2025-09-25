# IWbemServices::GetObject

## Description

The
**IWbemServices::GetObject** method retrieves a class or instance. This method only retrieves objects from the namespace associated with the current
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) object.

## Parameters

### `strObjectPath` [in]

Path of the object to retrieve. If this is **NULL**, an empty object is returned that can become a new class. For more information, see
[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class).

### `lFlags` [in]

The following flags affect the behavior of this method.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_RETURN_WBEM_COMPLETE

This flag makes this a synchronous call.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag makes this a semisynchronous call. You must provide a valid pointer for the *ppCallResult* parameter. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_DIRECT_READ

This flag causes direct access to the provider for the class specified without any regard to its parent class or subclasses.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is producing the requested class or instance. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppObject` [out]

If not **NULL**, this receives the object, if it is found. The returned object has a positive reference count. The caller must use **Release** when the object is no longer needed. In all cases of error, this parameter is set to point to **NULL**.

### `ppCallResult` [out]

If **NULL**, this parameter is not used. If the *lFlags* parameter contains **WBEM_FLAG_RETURN_IMMEDIATELY**, this call returns immediately with **WBEM_S_NO_ERROR**. The *ppCallResult* parameter receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object, which can then be polled to obtain the result using the
[GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) method. The caller can call
[IWbemCallResult::GetResultObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultobject) to retrieve the object when it becomes available.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## See also

[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class)

[Describing the Location of a WMI Object](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-the-location-of-a-wmi-object)

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::GetObjectAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobjectasync)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)