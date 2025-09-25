# ISearchCompletedCallback::Invoke

## Description

Handles the notification of the completion of an asynchronous search that is initiated by calling the [IUpdateSearcher.BeginSearch](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-beginsearch) method.

## Parameters

### `searchJob` [in]

An [ISearchJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchjob) interface that contains search information.

### `callbackArgs` [in]

This parameter is reserved for future use and can be ignored. An [ISearchCompletedCallbackArgs](https://learn.microsoft.com/previous-versions/windows/desktop/aa386067(v=vs.85)) interface that contains information on the completion of an asynchronous search.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[ISearchCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchcompletedcallback)

[IUpdateSearcher::BeginSearch](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-isearchcompletedcallback-invoke)