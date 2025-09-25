# WinHttpTimeFromSystemTime function

## Description

The **WinHttpTimeFromSystemTime** function formats a date and time according to the HTTP version 1.0 specification.

## Parameters

### `pst` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date and time to format.

### `pwszTime` [out]

A pointer to a string buffer that receives the formatted date and time. The buffer should equal to the size, in bytes, of WINHTTP_TIME_FORMAT_BUFSIZE.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Error codes include the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHTTP Start Page.

#### Examples

The following code example code shows how to convert a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure to a string that contains the time in HTTP format.

```cpp
    SYSTEMTIME  sTime;
    LPWSTR      pwszTimeStr;

    // Get the current time.
    GetSystemTime(&sTime);

    // Allocate memory for the string.
    // Note: WINHTTP_TIME_FORMAT_BUFSIZE is a byte count.
    //       Therefore, you must divide the array by
    //       sizeof WCHAR to get the proper string length.
    pwszTimeStr = new WCHAR[WINHTTP_TIME_FORMAT_BUFSIZE/sizeof(WCHAR)];

    // Convert the current time to HTTP format.
    if(!WinHttpTimeFromSystemTime( &sTime, pwszTimeStr))
    {
        printf( "Error %u in WinHttpTimeFromSystemTime.\n", GetLastError());
    }
    else
    {
        // Print the time.
        printf("Current time is (%S)\n", pwszTimeStr);
    }

    // Free the memory.
    delete [] pwszTimeStr;

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttptimetosystemtime)