# HTTP_VERSION_INFO structure

## Description

Contains the global HTTP version.

## Members

### `dwMajorVersion`

The major version number. Must be 1.

### `dwMinorVersion`

The minor version number. Can be either 1 or zero.

## Remarks

On Windows 7, Windows Server 2008 R2, and later, the value in the **HTTP_VERSION_INFO** structure is overridden by Internet Explorer settings. **EnableHttp1_1** is a registry value under **HKLM\Software\Microsoft\InternetExplorer\AdvacnedOptions\HTTP\GENABLE** controlled by Internet Options set in Internet Explorer for the system. The **EnableHttp1_1** value defaults to 1. The **HTTP_VERSION_INFO** structure is ignored for any HTTP version less than 1.1 if **EnableHttp1_1** is set to 1.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)

[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona)