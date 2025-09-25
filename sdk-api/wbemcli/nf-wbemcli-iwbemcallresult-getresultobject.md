# IWbemCallResult::GetResultObject

## Description

The
**IWbemCallResult::GetResultObject** method attempts to retrieve an object from a previous semisynchronous call to
[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) or
[IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod). If the object is not yet available, the call returns **WBEM_S_TIMEDOUT**. Also, before invoking this method to get the resulting object, you may call
[IWbemCallResult::GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) until it returns **WBEM_S_NO_ERROR**, indicating that the original semisynchronous operation is complete.

## Parameters

### `lTimeout` [in]

Specifies the maximum time in milliseconds that this call blocks before returning. If you use the constant **WBEM_INFINITE** (0xFFFFFFFF), the call blocks until the object is available. If you use 0, the call immediately returns either the object or a status code.

### `ppResultObject` [out]

This parameter cannot be **NULL**. It receives the copy of the object when it becomes available. You must call **IWbemClassObject::Release** on the returned object when the object is no longer required. A new object is not returned on error.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

If the original semisynchronous operation failed (such as when the object was not found, or the method could not be invoked), this method returns the error code that the original function would have returned in its synchronous version.

On error, you can call the COM function **GetErrorInfo** to obtain more error information.

COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

## See also

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod)

[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject)