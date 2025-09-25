# ISearchScopeRule::get_PatternOrURL

## Description

Gets the pattern or URL for the rule. The scope rules determine what URLs or paths to include or exclude.

## Parameters

### `ppszPatternOrURL` [out, retval]

Type: **LPWSTR***

On return, contains the address of a pointer to a null-terminated, Unicode buffer that contains the pattern or URL string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A standard URL might look like this:  `outlookexpress://{User sid}/{Identity}/Inbox)`

A pattern might look like this:  `file:///c:\documents and settings\*\application data\*`

Only exclusion rules use patterns.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.