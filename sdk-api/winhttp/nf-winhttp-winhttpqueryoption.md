# WinHttpQueryOption function

## Description

The **WinHttpQueryOption** function queries an Internet option on the specified handle.

## Parameters

### `hInternet` [in]

An **HINTERNET** handle on which to query information. Note that this can be either a Session handle or a Request handle, depending on what option is being queried; see the [Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags) topic to determine which handle is appropriate to use in querying a particular option.

### `dwOption` [in]

An unsigned long integer value that contains the Internet option to query. This can be one of the
[Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags) values.

### `lpBuffer` [out]

A pointer to a buffer that receives the option setting. Strings returned by the
**WinHttpQueryOption** function are globally allocated, so the calling application must globally free the string when it finishes using it. Setting this parameter to **NULL** causes this function to return **FALSE**. Calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) then returns ERROR_INSUFFICIENT_BUFFER and
*lpdwBufferLength* contains the number of bytes required to hold the requested information.

### `lpdwBufferLength` [in, out]

A pointer to an unsigned long integer variable that contains the length of
*lpBuffer*, in bytes. When the function returns, the variable receives the length of the data placed into
*lpBuffer*. If
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, this parameter receives the number of bytes required to hold the requested information.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following:

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_OPTION** | An invalid option value was specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the ERROR_INVALID_PARAMETER if an option flag that is invalid for the specified handle type is passed to the
*dwOption* parameter.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

This example demonstrates retrieving the connection
time-out value:

```cpp
    DWORD data;
    DWORD dwSize = sizeof(DWORD);

    // Use WinHttpOpen to obtain an HINTERNET handle.
    HINTERNET hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
                                    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                    WINHTTP_NO_PROXY_NAME,
                                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession)
    {

        // Use WinHttpQueryOption to retrieve internet options.
        if (WinHttpQueryOption( hSession,
                                WINHTTP_OPTION_CONNECT_TIMEOUT,
                                &data, &dwSize))
        {
            printf("Connection timeout: %u ms\n\n",data);
        }
        else
        {
            printf( "Error %u in WinHttpQueryOption.\n", GetLastError());
        }

        // When finished, release the HINTERNET handle.
        WinHttpCloseHandle(hSession);
    }
    else
    {
        printf("Error %u in WinHttpOpen.\n", GetLastError());
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)