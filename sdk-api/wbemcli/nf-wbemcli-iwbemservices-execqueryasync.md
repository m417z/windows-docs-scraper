# IWbemServices::ExecQueryAsync

## Description

The **IWbemServices::ExecQueryAsync** method executes a query to retrieve objects asynchronously.

## Parameters

### `strQueryLanguage` [in]

Valid **BSTR** that contains one of the query languages that Windows Management Instrumentation (WMI) supports. This must be "WQL".

### `strQuery` [in]

Valid **BSTR** that contains the text of the query. This cannot be
**NULL**. When you implement an instance provider, your provider can refuse the query
because it is too complex. When a provider determines that a query is too complex, WMI can retry the provider with
a simple query, or choose to retrieve and enumerate the superset of the query instances.

For more information on building WMI query strings, see
[Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql) and the
[WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/wql-sql-for-wmi) reference.

### `lFlags` [in]

This parameter can be one of the following values.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_BIDIRECTIONAL

This flag causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator.

#### WBEM_FLAG_SEND_STATUS

This flag registers a request with WMI to receive intermediate status reports through the client's implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change.

#### WBEM_FLAG_ENSURE_LOCATABLE

This flag ensures that returned objects have enough information in them so that the system properties, such as **__PATH**, **__RELPATH**, and **__SERVER**, are non-**NULL**.

#### WBEM_FLAG_PROTOTYPE

This flag is used for prototyping. It does not execute the query, but returns an object that looks like a typical result object.

#### WBEM_FLAG_DIRECT_READ

This flag causes direct access to the provider for the class specified without regard to its parent class or subclasses.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that the provider can use to return the requested classes or instances. The values in the context object must be specified in the documentation for the provider. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the objects in the query result set as they become available. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management Instrumentation (WMI) calls
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) with the objects any number of times, followed by a single call to [IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) to indicate the final status.

WMI only calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to the pointer when **WBEM_S_NO_ERROR** returns. When an error code returns, the reference count is the same as on entry. For a detailed explanation of asynchronous calling methods, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

When there is a failure, you can obtain information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo).

Other error codes are returned to the object sink specified by the *pResponseHandler* parameter.

COM-specific error codes might be returned if network problems cause you to lose the remote connection to WMI.

When finished, an instance provider can report success or failure with either the return code from
**ExecQueryAsync** or through a call to
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) made through *pResponseHandler*. If you choose to call
**SetStatus**, the return code sent through *pResponseHandler* takes precedence.

## Remarks

There are limits to the number of AND and OR keywords that can be used in WQL queries. Large numbers of WQL keywords used in a complex query can cause WMI to return the **WBEM_E_QUOTA_VIOLATION** error code as an **HRESULT** value. The limit of WQL keywords depends on how complex the query is.

The caller's [IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method can be called to report intermittent status. The [IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set.

When a provider does not support query processing, WMI can support it. However, a provider implementation of query processing is probably more efficient than the WMI version. To support queries, your instance provider must implement the
**ExecQueryAsync** method. If a provider supports
**ExecQueryAsync**, WMI sends a simple unary SELECT query directly to the provider through the *strQuery* parameter and the provider must parse the query and return the relevant instances. The provider must parse the query because WMI does not modify the query—even when the query is written in WQL.

To use WMI for query processing, do not set the **QuerySupportLevels** property in your [__InstanceProviderRegistration](https://learn.microsoft.com/windows/desktop/WmiSdk/--instanceproviderregistration). When you do this, WMI calls your implementation of [CreateInstanceEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenumasync) and post filters the results so that the caller only gets those instances that meet the query criteria.

The following example shows a typical instance provider implementation of
**ExecQueryAsync**. The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. It may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions occur.

Because the call-back might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information, see [IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

```cpp
HRESULT CStdProvider::ExecQueryAsync(
            /* [in] */ BSTR strQueryLanguage,
            /* [in] */ BSTR strQuery,
            /* [in] */ long lFlags,
            /* [in] */ IWbemContext __RPC_FAR *pCtx,
            /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler
            )
{
   IWbemClassObject *pClass = 0;

// Parse the query.
//   You must implement ParseQuery().
    if (!ParseQuery(strQuery))  return WBEM_E_PROVIDER_NOT_CAPABLE;

// Assume there is an IWbemServices pointer (m_pSvc) available to
// retrieve the class definition.

    HRESULT hRes = m_pSvc->GetObject(L"ClassName", 0, NULL, &pClass, 0);
    if (FAILED(hRes))
        return hRes;

// Call a method to determine number of instances returned.
// You need to implement the GetNumberInst function.
    int iNumInst = GetNumberInst();

// Now loop through the private source and create each
// instance which is part of the result set of the query.
    for (int iCnt = 0 ; iCnt < iNumInst ; iCnt++)
    {
// Prepare an empty object to receive the class definition.
         IWbemClassObject *pNextInst = 0;
         hRes = pClass->SpawnInstance(0, &pNextInst);

// Create the instance.
//   You must implement FillInst().
         /*FillInst(pNextInst, iCnt);*/

// Deliver the class to WMI.
         pResponseHandler->Indicate(1, &pNextInst);
         pNextInst->Release( );
    }

// Clean up memory
    pClass->Release();

// Send finish message to WMI.

    pResponseHandler->SetStatus(0, hRes, 0, 0);

    return hRes;
}
```

In the previous example, the instance provider acquires a thread from WMI to perform the necessary synching operations. You can call the sink [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and create another thread to deliver the objects in the result set. Creating another thread allows the current thread to return to WMI without depleting the thread pool. Whether the provider chooses the single thread design or the dual thread design depends on how long the provider plans to use the WMI thread. There are no fixed rules. Experimentation can help you determine how your design affects WMI performance.

**Note** When providers implement
**ExecQueryAsync**, they are expected by default to return the correct result set based on the query. If a provider cannot return the correct result set easily, it may return a superset of the results and request that WMI do post-filtering before delivering the objects to the client to ensure that the result set is correct. To do this, the provider calls
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) on the sink provided to its
**ExecQueryAsync** implementation, with the following flags.

```cpp
// The pSink variable is of type IWbemObjectSink*
pSink->SetStatus(WBEM_STATUS_REQUIREMENTS,
    WBEM_REQUIREMENTS_START_POSTFILTER, 0, 0);
```

**Note** Any objects subsequently sent to the WMI service are filtered. The provider can turn off post-filtering in mid-stream by using the following call.

```cpp
// The pSink variable is of type IWbemObjectSink*
pSink->SetStatus(WBEM_STATUS_REQUIREMENTS,
    WBEM_REQUIREMENTS_STOP_POSTFILTER, 0, 0);
```

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery)

[Querying with WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-with-wql)