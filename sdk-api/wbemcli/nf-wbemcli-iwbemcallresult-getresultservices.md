# IWbemCallResult::GetResultServices

## Description

The
**IWbemCallResult::GetResultServices** method retrieves the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer, which results from a semisynchronous call to
[IWbemServices::OpenNamespace](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-opennamespace) when it becomes available.

## Parameters

### `lTimeout` [in]

The maximum time in milliseconds that this call blocks before it returns. If you use the constant **WBEM_INFINITE** (0xFFFFFFFF), the call blocks until the interface pointer is available. If you use 0, the call immediately returns either the pointer or a status code.

### `ppServices` [out]

Cannot be **NULL**. It receives a pointer to the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) interface requested by the original call to
[OpenNamespace](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-opennamespace) when it becomes available The caller must call [IWbemServices::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned object when it is no longer required.

On error, a new object is not returned.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On error, the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo) can be called to obtain more error information.

COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

## See also

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices::OpenNamespace](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-opennamespace)