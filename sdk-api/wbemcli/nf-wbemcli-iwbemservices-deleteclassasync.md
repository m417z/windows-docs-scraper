# IWbemServices::DeleteClassAsync

## Description

The
**IWbemServices::DeleteClassAsync** method deletes the specified class from the current namespace. This method is identical to
[IWbemServices::DeleteClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclass) except that the call returns immediately. Confirmation or failure is asynchronously reported to the specified object sink using the
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method after the operation is complete.

## Parameters

### `strClass` [in]

Name of the class targeted for deletion.

### `lFlags` [in]

One or more of the following values are valid.

#### WBEM_FLAG_SEND_STATUS

This flag registers with Windows Management a request to receive intermediate status reports through the client's implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting, for this flag to change behavior.

#### WBEM_FLAG_OWNER_UPDATE

Push providers must specify this flag when calling
**DeleteClassAsync** to indicate that this class has changed.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider deleting the class. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to an implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) implemented by the caller. This handler receives the status of the deletion request when it becomes available through the
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management only calls **AddRef** on the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For a detailed explanation of this parameter, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

All other return codes are provided to the object sink specified by the *pReponseHandler* parameter through the
**SetStatus** method. Error conditions, such as when the class does not exist or the user does not have permission to delete classes, are reported to the handler. They are not reported in the return code of this method.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

If a dynamic instance provider is associated with the class, the provider is unregistered, and is no longer called for that class. Any classes that derive from the deleted class are also deleted, and their associated providers become unregistered. All outstanding static instances of the specified class and its subclasses are also deleted when the class is deleted.

If the class is provided by a dynamic class provider, the success of the deletion depends on whether class deletion is supported by that provider.

**Note** Standard system classes cannot be deleted.

Because the call-back might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IWbemServices::DeleteClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclass) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## See also

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::DeleteClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclass)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)