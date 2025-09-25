# WinHttpTimeToSystemTime function

## Description

The **WinHttpTimeToSystemTime** function takes an HTTP time/date string and converts it to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure.

## Parameters

### `pwszTime` [in]

Pointer to a null-terminated date/time string to convert. This value must use the format defined in section 3.3 of the [RFC2616](http://www.ietf.org/rfc/rfc2616.txt).

### `pst` [out]

Pointer to the
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the converted time.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned is:

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

This example shows how to convert an HTTP formatted date to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure.

```cpp
    SYSTEMTIME  sTime;
    LPCWSTR     pwszTimeStr = L"Tue, 21 Nov 2000 01:06:53 GMT";

    // Convert the HTTP string to a SYSTEMTIME structure.
    if (!WinHttpTimeToSystemTime( pwszTimeStr, &sTime))
    {
        printf( "Error %u in WinHttpTimeToSystemTime.\n", GetLastError());
    }
    else
    {
        // Print the date.
        printf( "The U.S. formatted date is (%u/%u/%u)\n",
                sTime.wMonth, sTime.wDay, sTime.wYear);
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpTimeFromSystemTime](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttptimefromsystemtime)