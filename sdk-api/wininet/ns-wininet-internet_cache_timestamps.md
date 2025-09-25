# INTERNET_CACHE_TIMESTAMPS structure

## Description

Contains the LastModified and Expire times for a resource stored in the Internet cache.

## Members

### `ftExpires`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the Expires time.

### `ftLastModified`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the LastModified time.

## Remarks

This structure is returned in the buffer when calling
[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) with the
[INTERNET_OPTION_CACHE_TIMESTAMPS](https://learn.microsoft.com/windows/desktop/WinInet/option-flags) flag.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)