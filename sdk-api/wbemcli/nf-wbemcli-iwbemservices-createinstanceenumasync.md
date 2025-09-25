# IWbemServices::CreateInstanceEnumAsync

## Description

The
**IWbemServices::CreateInstanceEnumAsync** method creates an enumerator that asynchronously returns the instances of a specified class according to user-specified selection criteria. This method supports simple WMI Query Language (WQL) queries. More complex queries can be processed using the
[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync) method.

## Parameters

### `strFilter` [in]

Valid **BSTR** containing the name of the class for which instances are desired. This parameter cannot be **NULL**.

### `lFlags` [in]

This parameter can be one of the following values.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, Windows Management Instrumentation (WMI) retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_DEEP

This flag forces the enumeration to include instances of this and all subclasses in the hierarchy.

#### WBEM_FLAG_SHALLOW

This flag forces the enumeration to include only pure instances of this class, excluding all instances of subclasses, which supply properties not found in this class.

#### WBEM_FLAG_SEND_STATUS

This flag registers with Windows Management a request to receive intermediate status reports through the clients implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change behavior.

#### WBEM_FLAG_BIDIRECTIONAL

This flag causes Windows Management to retain pointers to objects of the enumeration until the client releases the enumerator.

#### WBEM_FLAG_DIRECT_READ

This flag causes direct access to the provider for the class specified without any regard to its parent class or subclasses.

### `pCtx` [in]

Typically NULL. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is returning the requested instances. The values in the context object must be specified in the documentation for the provider in question. For more information, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the objects as they become available. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation will be called to indicate the result of the operation. Windows Management only calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain more information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

An instance provider can report success or failure with either the return code from
**CreateInstanceEnumAsync**, or through a call to
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) made through *pResponseHandler*. If you choose to call
**SetStatus**, the return code sent through *pResponseHandler* takes precedence.

If
**CreateInstanceEnumAsync** returns **WBEM_S_NO_ERROR**, WMI waits for a result from the
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method of the response handler. WMI waits indefinitely on a local connection, or until a remote connection time-out occurs.

## Remarks

The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. It may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions occur.

Because the callback might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication.

For more information, see [IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

The following example shows you how to implement
**CreateInstanceEnumAsync**.

```cpp
#define NUM_OF_INSTANCES 3

HRESULT CStdProvider::CreateInstanceEnumAsync(
            /* [in] */ BSTR strClass,
            /* [in] */ long lFlags,
            /* [in] */ IWbemContext __RPC_FAR *pCtx,
            /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler
            )
{
    IWbemClassObject *pClass = 0;
    IWbemClassObject *pNextInst = 0;

    // Assume there is an IWbemServices pointer available to
    // retrieve the class definition.
    HRESULT hRes = m_pSvc->GetObject(strClass, 0, NULL, &pClass, 0);
    if (hRes)
        return hRes;

    // Now loop through the private source and create each instance.
    for (int i = 0; i < NUM_OF_INSTANCES; i++)
    {
         // Prepare an empty object to receive the class definition.
         pClass->SpawnInstance(0, &pNextInst);

         // Create the instance.
         // For example, create the instance in a
         // FillInst method you implement:
         /*FillInst(pNextInst);*/

         // Deliver the class to WMI.
         pResponseHandler->Indicate(1, &pNextInst);
         pNextInst->Release();
    }

    // Send a finish message to WMI.
    pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, 0, 0);

    // Free memory resources.
    SysFreeString(strClass);
    pClass->Release();
    m_pSvc->Release();

    return WBEM_S_NO_ERROR;
}
```

In the previous example, the instance provider acquires a thread from WMI to perform any necessary operations. You may want to call the sink [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and create another thread for delivering the objects in the result set. Creating another thread allows the current thread to return to WMI without depleting the thread pool. Whether or not the provider chooses the single thread design over the dual thread design depends on how long the provider plans to use the WMI thread. There are no fixed rules. Experimentation can help you determine how your design affects WMI performance.

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum)