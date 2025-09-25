# IOpenSearchSource::GetResults

## Description

Returns search results, from an OpenSearch data source, formatted in RSS or Atom format.

## Parameters

### `hwnd` [in]

Type: **HWND**

The window handle of the caller.

### `pszQuery` [in]

Type: **LPCWSTR**

The query as entered by the user. This parameter is equivalent to the OpenSearch {searchTerms} parameter and may be empty.

### `dwStartIndex` [in]

Type: **DWORD**

The index of the first result being requested. Equivalent to the OpenSearch {startIndex} parameter. See Remarks below.

### `dwCount` [in]

Type: **DWORD**

The number of results being requested. Equivalent to the OpenSearch {count} parameter.

### `riid` [in]

Type: **REFIID**

The IID of the interface being requested. Typically IID_IStream.

### `ppv` [out]

Type: **void****

An interface pointer, of type specified by RIID, to the object containing the results in Atom or RSS format.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. B_S_ENDOFROWSET optionally signifies the end of the results. The following errors display appropriate error messages in the info bar:

* INET_E_AUTHENTICATION_REQUIRED (user does not have permission to access this resource)
* INET_E_RESOURCE_NOT_FOUND (location was unavailable)
* INET_E_DOWNLOAD_FAILURE (server error)

## Remarks

Windows Explorer calls this method with the search query parameters. The [IOpenSearchSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iopensearchsource) implementation returns some or all results after performing required actions, such as providing custom authentication UI or connecting to the data source using a proprietary API.

### Paged Results

If you do not want the web service to return more than a limited number of results per request, this method can return just a "page" of results at a time. Windows Explorer can get additional pages of results by calling this method repeatedly and specifying a new index number. When returning results, the first result must be the result at the index requested by *dwStartIndex*.

### Index Numbers and Counts

The index number identifies the first result on a page of results. It is equivalent to the OpenSearch {startIndex} parameter. The count, equivalent to the OpenSearch {count} parameter, identifies the expected or preferred number of items returned per page.

If a web service returns 20 items on the first page of results, the expected page size is 20. To get the next 20 items, Windows Explorer would call **IOpenSearchSource::GetResults** with the value 21 for *dwStartIndex* and with the value of 20 for *dwCount*. When a page of results returned by the web service has fewer items than the expected page size, Windows Explorer assumes it has received the last page of results and stops making requests.

## See also

[IOpenSearchSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iopensearchsource)