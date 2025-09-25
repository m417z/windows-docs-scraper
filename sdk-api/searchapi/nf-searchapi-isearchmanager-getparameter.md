# ISearchManager::GetParameter

## Description

Not supported.

This method returns E_INVALIDARG when called.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

There are currently no valid parameters in this version of search (WDS 3.0).

### `ppValue` [out, retval]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)****

Returns a value in an undefined state as there are no properties currently defined to retrieve values from.

## Return value

Type: **HRESULT**

This method returns E_InvalidArg as an error code when called.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.