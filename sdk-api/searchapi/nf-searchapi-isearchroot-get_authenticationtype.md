# ISearchRoot::get_AuthenticationType

## Description

Retrieves the type of authentication needed to access the URLs under this search root.

## Parameters

### `pAuthType` [out, retval]

Type: **[AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-auth_type)***

A pointer to a value from the [AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-auth_type) enumeration that indicates the authentication type required to access URLs under this search root.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.