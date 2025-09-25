# IWbemServices::DeleteInstanceAsync

## Description

The
**IWbemServices::DeleteInstanceAsync** method asynchronously deletes an instance of an existing class in the current namespace. The confirmation or failure of the operation is reported through the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) interface implemented by the caller.

## Parameters

### `strObjectPath` [in]

Valid **BSTR** that contains the
[object path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-an-instance-object-path) of the object to be deleted.

### `lFlags` [in]

**WBEM_FLAG_SEND_STATUS** registers with Windows Management a request to receive intermediate status reports through the client's implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting, for this flag to change behavior. Note that the **WBEM_FLAG_USE_AMENDED_QUALIFIERS** flag cannot be used here.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is deleting the instance. The values in the context object must be specified in the documentation for the provider in question.

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the status of the delete operation as it becomes available through the
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management only calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo).

If
**DeleteInstanceAsync** returns **WBEM_S_NO_ERROR**, WMI waits for a result from the
**SetStatus** method of the response handler. WMI waits indefinitely on a local connection, or until a remote connection time-out occurs.

Other error conditions are reported asynchronously to the object sink supplied by the *pResponseHandler* parameter.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

**Note** Clients that call
**DeleteInstanceAsync** must always expect the results of the call to be reported using their
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method.

**Note** When the instance pointed to by *strObjectPath* belongs to a class that is a member of a class hierarchy, the success of
**DeleteInstanceAsync** depends on the topmost non-abstract provider. For a detailed explanation of the dependencies involved that determine the success of this operation, see Remarks in
[IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance).

## Remarks

An instance provider can report success or failure with either the return code from
**DeleteInstanceAsync** or through a call to
**SetStatus** made through *pResponseHandler*. If sent to
**SetStatus**, the return code sent to the sink through *pResponseHandler* takes precedence. Because the callback might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[Describing an Instance Object Path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-an-instance-object-path)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance)