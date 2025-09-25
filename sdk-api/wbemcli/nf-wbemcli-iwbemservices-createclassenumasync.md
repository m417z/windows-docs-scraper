# IWbemServices::CreateClassEnumAsync

## Description

The
**IWbemServices::CreateClassEnumAsync** method returns an enumeration of all classes that the class provider supports. The class provider creates each class definition from scratch and only returns subclasses of the requested class. As an asynchronous method,
**CreateClassEnumAsync** returns a status message immediately and then updates the sink passed through the *pResponseHandler* parameter—if necessary.

When a call succeeds, WMI calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer *pResponseHandler*, returns immediately, and then asynchronously calls *pResponseHandler*– >
[Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) from another thread with class definitions until the query is satisfied.

## Parameters

### `strSuperclass` [in]

If not **NULL** or blank, this parameter specifies a parent class name. Only classes that are subclasses of this class are returned in the enumerator. If **NULL** or blank, and *lFlags* is **WBEM_FLAG_SHALLOW**, only top-level classes—those that have no parent class—are returned. If it is **NULL** or blank and *lFlags* is **WBEM_FLAG_DEEP**, all classes within the namespace are returned.

### `lFlags` [in]

One or more of the following values are valid.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, Windows Management Instrumentation (WMI) retrieves the amended qualifiers stored in the localized namespace of the current connection locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_BIDIRECTIONAL

This flag causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator.

#### WBEM_FLAG_DEEP

This flag forces the enumeration to include this and all subclasses in the hierarchy.

#### WBEM_FLAG_SHALLOW

This flag forces the enumeration to include only pure instances of this class, excluding all instances of subclasses that supply properties not found in this class.

#### WBEM_FLAG_SEND_STATUS

This flag registers a request in WMI to receive intermediate status reports through the client implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change behavior.

**Note** If *strSuperclass* is **NULL** or blank and **WBEM_FLAG_DEEP** is specified, all classes are returned.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that can be used by the provider that returns the requested classes. The values in the context object must be specified in the documentation for the provider. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the objects as they become available by using the
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method. When no objects are available, the
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called by WMI. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If WBEM_S_NO_ERROR is returned, then the user
**IWbemObjectSink** implementation is called to indicate the result of the operation. WMI only calls **AddRef** on the pointer when **WBEM_S_NO_ERROR** returns. When an error code returns, the reference count is the same as no entry. For a detailed explanation of this parameter, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** that indicates the status of the method call. On failure, you can obtain available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo). COM-specific error codes can be returned if network problems cause you to lose the remote connection to WMI. Note that if
**CreateClassEnumAsync** returns WBEM_S_NO_ERROR, WMI waits for a result from the
**SetStatus** method of the response handler. WMI waits indefinitely on a local connection or until a remote connection time-out occurs. The following list lists the value contained within an **HRESULT**.

## Remarks

Because the callback might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IWbemServices::CreateClassEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenum) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

The following code example shows how to implement
**CreateClassEnumAsync**.

```cpp
HRESULT CStdProvider::CreateClassEnumAsync(
            /* [in] */ BSTR strSuperclass,
            /* [in] */ long lFlags,
            /* [in] */ IWbemContext __RPC_FAR *pCtx,
            /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler
            )
{
    IWbemClassObject *pClass = 0;

    // Assume there is an IWbemServices pointer available (m_pSvc).
    // Retrieve an 'empty' object that will be built up
    // into the class definition.

    HRESULT hRes = m_pSvc->GetObject(NULL, 0, NULL, &pClass, 0);
    if (hRes)
    {
        return hRes;
    }

    // Prepare an empty object to receive the class definition.
        IWbemClassObject *pNextClass = 0;
        hRes = pClass->Clone(&pNextClass);

    // Now loop through the private source of class definitions
    // and create each class.
    while(hRes)
    {
        // Create the class definition elsewhere.
        // For example, call a function that creates a definition:
        // FillClassDef(pNextClass);

        // Deliver the class to WMI.
        pResponseHandler->Indicate(1, &pNextClass);
        pNextClass->Release( );

        // Prepare an empty object to receive the class definition.
        IWbemClassObject *pNextClass = 0;
        hRes = pClass->Clone(&pNextClass);
    }

    pClass->Release();

    // Send a finish message to WMI.

    pResponseHandler->SetStatus(0, hRes, 0, 0);

    return hRes;
}
```

In the previous example, the class provider acquires a thread from WMI to perform the necessary operations. You may want to call the sink [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and create another thread to deliver the objects in the result set. Creating another thread allows the current thread to return to WMI without depleting the thread pool. Whether the provider chooses the single thread design or the dual thread design depends on the amount of time the provider plans to use the WMI thread. There are no fixed rules. Experimentation can help you determine how your design affects WMI performance.

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::CreateClassEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenum)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)