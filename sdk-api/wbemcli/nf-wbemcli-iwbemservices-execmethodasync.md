# IWbemServices::ExecMethodAsync

## Description

The
**IWbemServices::ExecMethodAsync** method asynchronously executes a method exported by a CIM object. The call immediately returns to the client while the inbound parameters are forwarded to the appropriate provider where it executes. Information and status are returned to the caller through the supplied object sink.

Methods are not directly implemented by Windows Management, but are exported by method providers. For any given CIM class, the available methods and their parameters are part of the documentation for the provider in question.

## Parameters

### `strObjectPath` [in]

Valid **BSTR** containing the
[object path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-a-class-object-path) of the object for which the method is to be executed. You can invoke a static method using either a class name or an object path to an instance. The method provider can parse the object path parameter to determine the class and instance that contain the method definition.

### `strMethodName` [in]

Name of the method for the object.

### `lFlags` [in]

**WBEM_FLAG_SEND_STATUS** registers with Windows Management a request to receive intermediate status reports through the clients implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change behavior. Note that the **WBEM_FLAG_USE_AMENDED_QUALIFIERS** flag cannot be used here.

### `pCtx` [in]

Typically **NULL**; otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider executing the method. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pInParams` [in]

Can be **NULL** if no inbound parameters are required to execute the method. Otherwise, this points to an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object that contains the properties acting as inbound parameters for the method execution. The contents of the object are method-specific, and are part of the specification for the provider in question. However, the most common object is an instance of the [__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) system class. For each input parameter to the method to be called, there is one non-system property. Method providers ignore the [ID](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-wmi-qualifiers) qualifiers attached to each parameter in the method, which are typically used only by browsers and similar applications.

### `pResponseHandler` [in]

Cannot be **NULL**. The object sink receives the result of the method call. The outbound parameters are sent to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate). The most common returned object is an instance of the [__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) system class. For more information about return codes, see the Remarks section. When implementing a method provider, you should call
**Indicate** to return output parameter information before calling
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) to report the final status.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo).

Other errors are reported asynchronously to the object sink supplied in the *pReponseHandler* parameter.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to WMI.

## Remarks

A single method provider can supply methods for many classes and instances. Method providers have to deal with a maximum of three return values.

The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. It may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions occur.

Because the call-back might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

| Return values | Description |
| --- | --- |
| **ExecMethodAsync** (required) | Indicates whether or not the input parameters for the method that are pointed to by the **pInParams** parameter are valid. |
| Invoked method (optional) | Dependent on the method. The return value is placed in the **ReturnValue** property of the [__PARAMETERS](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) instance representing the out parameters and returned through a call to [Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate). |
| Invoked method out parameters (optional) | Dependent on the method. Out parameters are placed in non-system properties of a [__PARAMETERS](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) instance and returned through [Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate). |

#### Examples

The following C++ example shows how to implement the
**IWbemServices::ExecMethodAsync** method for the **Echo** method of the **TestMeth** class. The **TestMeth** class supports a method that has one input parameter and one output parameter and that returns an unsigned 32-bit integer. The implementation assumes that there is only one method called **Echo** and one class that contains it. For the sake of brevity, there is no error checking or object path parsing.

```cpp
STDMETHODIMP CMyMethodProvider::ExecMethodAsync(BSTR ObjectPath,
    BSTR MethodName, long lFlags, IWbemContext* pCtx,
    IWbemClassObject* pInParams, IWbemObjectSink* pResultSink)
{
    HRESULT hr;
    IWbemClassObject * pClass = NULL;
    IWbemClassObject * pOutClass = NULL;
    IWbemClassObject* pOutParams;

    // Allocate some BSTRs.

    BSTR ClassName = SysAllocString(L"TestMeth");
    BSTR InputArgName = SysAllocString(L"sInArg");
    BSTR OutputArgName = SysAllocString(L"sOutArg");
    BSTR retValName = SysAllocString(L"ReturnValue");

    // Get the class object; this is hard-coded and matches the class
    // in the MOF.  A more sophisticated example would parse
    // ObjectPath to determine the class and possibly the instance.
    // The m_pWbemSvcs pointer is of type IWbemServices*
    hr = m_pWbemSvcs->GetObject(ClassName, 0, pCtx, &pClass, NULL);

    // This method returns values, and so creates an instance of the
    // output argument class.

    hr = pClass->GetMethod(MethodName, 0, NULL, &pOutClass);
    pOutClass->SpawnInstance(0, &pOutParams);

    // Copy the input argument into the output object.

    VARIANT var;
    VariantInit(&var);

    // Get the input argument.
    pInParams->Get(InputArgName, 0, &var, NULL, NULL);

    // Put it into the output object.
    pOutParams->Put(OutputArgName , 0, &var, 0);

    long lLen = wcslen(var.bstrVal);
    VariantClear(&var);
    var.vt = VT_I4;
    var.lVal = lLen;
    // Special name for the return value.
    pOutParams->Put(retValName , 0, &var, 0);

    // Send the output object back to the client by the sink. Then
    // release the pointers and free the strings.

    hr = pResultSink->Indicate(1, &pOutParams);
    pOutParams->Release();
    pOutClass->Release();
    pClass->Release();
    SysFreeString(ClassName);
    SysFreeString(InputArgName);
    SysFreeString(OutputArgName);
    SysFreeString(retValName);

    // All done; now set the status.

    hr = pResultSink->SetStatus(0,WBEM_S_NO_ERROR,NULL,NULL);
    return WBEM_S_NO_ERROR;
}
```

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IWbemCallResult::GetResultObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultobject)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::ExecMethodAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethodasync)