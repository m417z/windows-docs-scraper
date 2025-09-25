# ISearchRoot::put_AuthenticationType

## Description

Sets the type of authentication required to access the URLs under this search root.

## Parameters

### `authType` [in]

Type: **[AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-auth_type)**

A value from the [AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-auth_type) enumeration that indicates the authentication type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.