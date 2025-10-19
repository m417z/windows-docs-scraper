# IUpdateSearcher::EndSearch

## Description

Completes an asynchronous search for updates.

## Parameters

### `searchJob` [in]

The [ISearchJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchjob) interface that the [BeginSearch](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-beginsearch) method returns.

### `retval` [out]

An [ISearchResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchresult) interface that contains the following:

* The result of an operation
* A collection of updates that match the search criteria

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **S_OK** | An asynchronous search for updates is successful. |
| **WU_E_LEGACYSERVER** | You cannot search for updates if the [ServerSelection](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serverselection) property of [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) is set to [ssManagedServer](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md) or to [ssDefault](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md), and the managed server on a computer is a Microsoft Software Update Services (SUS) 1.0 server. |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_INVALID_OPERATION** | The [EndSearch](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-endsearch) method returns **WU_E_INVALID_OPERATION** if **EndSearch** has already been called for the search job. |
| **WU_E_INVALID_CRITERIA** | An invalid criteria was encountered during a search. |

## Remarks

When you use any asynchronous WUA API in your app, you might need to implement a time-out mechanism. For more info about how to perform asynchronous WUA operations, see [Guidelines for Asynchronous WUA Operations](https://learn.microsoft.com/windows/desktop/Wua_Sdk/guidelines-for-asynchronous-wua-operations).

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)