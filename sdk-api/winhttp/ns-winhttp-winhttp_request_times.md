## Description

The **WINHTTP\_REQUEST\_TIMES** structure contains a variety of timing information for a request.

## Members

### `cTimes`

Unsigned long integer value that contains the number of timings to retrieve. This should generally be set to **WinHttpRequestTimeLast**.

### `rgullTimes`

Array of unsigned long long integer values that will contain the returned timings, indexed by [**WINHTTP\_REQUEST\_TIME\_ENTRY**](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_request_time_entry).

Times are measured as performance counter values; for more information, see [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter).

## Remarks

This structure is used with [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) to retrieve timing information for a request by specifying the **WINHTTP\_OPTION\_REQUEST\_TIMES** flag.

## See also

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)

[QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter)