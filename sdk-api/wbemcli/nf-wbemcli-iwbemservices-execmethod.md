# IWbemServices::ExecMethod

## Description

The
**IWbemServices::ExecMethod** method executes a method exported by a CIM object. The method call is forwarded to the appropriate provider where it executes. Information and status are returned to the caller, which blocks until the call is complete.

Methods are not directly implemented by Windows Management, but are exported by method providers. For any given CIM class, the available methods and their parameters must be specified in the documentation for the provider in question.

For more information about executing methods, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Parameters

### `strObjectPath` [in]

Valid **BSTR** containing the
[object path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-a-class-object-path) of the object for which the method is executed.

### `strMethodName` [in]

Name of the method for the object.

### `lFlags` [in]

This parameter can be set to 0 to make this a synchronous call. To make this a semisynchronous call, set *lFlags* to **WBEM_FLAG_RETURN_IMMEDIATELY**, provide a valid pointer for the *ppCallResult* parameter, and this call returns immediately. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

### `pCtx` [in]

Typically **NULL**; otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider executing the method. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pInParams` [in]

May be **NULL** if no in-parameters are required to execute the method. Otherwise, this points to an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) that contains the properties acting as inbound parameters for the method execution. The contents of the object are method-specific, and are part of the specification for the provider in question. For more information about constructing input parameters, see [Creating Parameters Objects in C++](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-parameters-objects-in-c--).

### `ppOutParams` [out]

If not **NULL**, receives a pointer to the outbound parameters and return values for the method execution. The contents of this object are method-specific, and are part of the specification for the provider in question. The caller must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned object when it is no longer required.

### `ppCallResult` [out]

If **NULL**, this is not used. If *ppCallResult* is specified, it must be set to point to **NULL** on entry. In this case, the call returns immediately with **WBEM_S_NO_ERROR**. The *ppCallResult* parameter receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object, which must be polled to obtain the result of the method execution using the
[GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) method. The out parameters for the call are available by calling
[IWbemCallResult::GetResultObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultobject).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

If *ppOutParams* is not **NULL**, the client can determine the method's return value type by examining the **ReturnValue** property of the object pointed to by *ppOutParams*.

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IWbemCallResult::GetResultObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultobject)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::ExecMethodAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethodasync)