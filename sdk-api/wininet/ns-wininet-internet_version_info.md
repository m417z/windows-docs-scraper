# INTERNET_VERSION_INFO structure

## Description

Contains the HTTP version number of the server. This structure is used when passing the INTERNET_OPTION_VERSION flag to the
[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) function.

## Members

### `dwMajorVersion`

Major version number.

### `dwMinorVersion`

Minor version number.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)