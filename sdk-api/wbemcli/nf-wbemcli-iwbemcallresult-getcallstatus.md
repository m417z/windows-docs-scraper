# IWbemCallResult::GetCallStatus

## Description

The
**IWbemCallResult::GetCallStatus** method returns to the user the status of the current outstanding semisynchronous call. When this call returns **WBEM_S_NO_ERROR**, the original call to the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) method is complete.

## Parameters

### `lTimeout` [in]

Specifies the maximum time in milliseconds that this call blocks before it returns. If you use the constant **WBEM_INFINITE** (0xFFFFFFFF), the call blocks until the original semisynchronous call to an
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) method is complete. If you use 0 (zero), the call immediately returns the call status.

### `plStatus` [out]

If **WBEM_S_NO_ERROR** returns in the HRESULT to this method, this parameter will receive the final result status of a call to one of the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) methods:
[OpenNamespace](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-opennamespace),
[PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance),
[PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass),
[GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject),
[DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance),
[DeleteClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclass), or
[ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod). On error, the value pointed to by *plStatus* will not be used.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

On error, you can call the COM function **GetErrorInfo** to obtain more error information. COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

After invoking an
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) method semisynchronously, you can call
**GetCallStatus** at any time to determine whether the call is complete. After
**GetCallStatus** has returned **WBEM_S_NO_ERROR**, which indicates completion of the original
**IWbemServices** operation, calls to other
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) methods may be required to retrieve the result of the call, according to the following rules:

* For
  [IWbemServices::OpenNamespace](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-opennamespace), the
  [GetResultServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultservices) method must be called to retrieve the new
  [IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer.
* For
  [IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance), the
  [GetResultString](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultstring) method must be called to obtain the object path that was assigned to the object.
* For
  [IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject), the
  [GetResultObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultobject) method must be called to retrieve the object.
* For the
  [IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) methods
  [DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance),
  [DeleteClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclass), and
  [ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod), the
  **GetCallStatus** method is the only call that returns information regarding these operations.

## See also

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices::DeleteClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteclass)

[IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance)

[IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod)

[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject)

[IWbemServices::OpenNamespace](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-opennamespace)

[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance)