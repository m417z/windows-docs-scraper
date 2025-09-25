# IUpdateSearcher::BeginSearch

## Description

Begins execution of an asynchronous search for updates. The search uses the search options that are currently configured.

## Parameters

### `criteria` [in]

A string that specifies the search criteria.

### `onCompleted` [in]

An [ISearchCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchcompletedcallback) interface that is called when an asynchronous search operation is complete.

### `state` [in]

The caller-specific state that is returned by the [AsyncState](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-isearchjob-get_asyncstate) property of the [ISearchJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchjob) interface.

### `retval` [out]

An [ISearchJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchjob) interface that represents the current operation that might be pending.

The caller passes the returned value to the [EndSearch](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-endsearch) method to complete a search operation.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |

## Remarks

For a complete description of search criteria syntax, see [Search](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-search).

 As an alternative to implementing the [ISearchCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchcompletedcallback) interface, you can use a script to implement a callback routine of any identifier with DISPID 0 on an automation object. The type of the *onCompleted* parameter is **IUnknown***.

When you use any asynchronous WUA API in your app, you might need to implement a time-out mechanism. For more info about how to perform asynchronous WUA operations, see [Guidelines for Asynchronous WUA Operations](https://learn.microsoft.com/windows/desktop/Wua_Sdk/guidelines-for-asynchronous-wua-operations).

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)