# IWbemServices::DeleteClass

## Description

The
**IWbemServices::DeleteClass** method deletes the specified class from the current namespace. If a dynamic instance provider is associated with the class, the provider is unregistered, and it is no longer called for by that class. Any classes that derive from the deleted class are also deleted, and their associated providers are unregistered. All outstanding static instances of the specified class and its subclasses are also deleted when the class is deleted.

If a dynamic class provider provides the class, the success of the deletion depends on whether the provider supports class deletion.

**Note** System classes cannot be deleted.

## Parameters

### `strClass` [in]

Name of the class targeted for deletion.

### `lFlags` [in]

One of the following values can be set.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes this to be a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_OWNER_UPDATE

Indicates that the caller is a push provider.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider deleting the class. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppCallResult` [out]

If **NULL**, this parameter is not used. If *ppCallResult* is specified, it must be set to point to **NULL** on entry. If the *lFlags* parameter contains **WBEM_FLAG_RETURN_IMMEDIATELY**, this call returns immediately with **WBEM_S_NO_ERROR**. The *ppCallResult* parameter receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object, which can then be polled to obtain the result using the
[GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) method.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

## See also

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::DeleteClassAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclassasync)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)