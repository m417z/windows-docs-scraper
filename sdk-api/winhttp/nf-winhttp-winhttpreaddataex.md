## Description

Reads data from a handle opened by the [WinHttpOpenRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopenrequest) function.

## Parameters

### `hRequest`

Type: IN **[HINTERNET](https://learn.microsoft.com/windows/win32/winhttp/hinternet-handles-in-winhttp)**

An **HINTERNET** handle returned from a previous call to [WinHttpOpenRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopenrequest).

[WinHttpReceiveResponse](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpreceiveresponse) or [WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpquerydataavailable) must have been called for this handle and must have completed before **WinHttpReadDataEx** is called. Although calling **WinHttpReadDataEx** immediately after completion of **WinHttpReceiveResponse** avoids the expense of a buffer copy, doing so requires that your application use a fixed-length buffer for reading.

### `lpBuffer`

Type: \_Out\_writes\_bytes\_to\_(dwNumberOfBytesToRead, *lpdwNumberOfBytesRead) \_\_out\_data\_source(NETWORK) **[LPVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a buffer that receives the data read. Make sure that this buffer remains valid until **WinHttpReadDataEx** has completed.

### `dwNumberOfBytesToRead`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Unsigned long integer value that contains the number of bytes to read.

### `lpdwNumberOfBytesRead`

Type: OUT **[LPDWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to an unsigned long integer variable that receives the number of bytes read.
**WinHttpReadDataEx** sets this value to zero before doing any work or error checking. When using WinHTTP asynchronously, always set this parameter to **NULL** and retrieve the information in the callback function; not doing so can cause a memory fault.

### `ullFlags`

Type: IN **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If you pass **WINHTTP_READ_DATA_EX_FLAG_FILL_BUFFER**, then WinHttp won't complete the call to **WinHttpReadDataEx** until the provided data buffer has been filled, or the response is complete. Passing this flag makes the behavior of this API equivalent to that of [WinHttpReadData](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpreaddata).

### `cbProperty`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved. Pass 0.

### `pvProperty`

Type: \_In\_reads\_bytes\_opt\_(cbProperty) **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved. Pass NULL.

## Return value

A status code indicating the result of the operation. Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_CONNECTION_ERROR** | The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP 5.1 does not support SSL2 unless the client specifically enables it. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW** | Returned when an incoming response exceeds an internal WinHTTP size limit. |
| **ERROR_WINHTTP_TIMEOUT** | The request has timed out. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

By default, **WinHttpReadDataEx** returns after any amount of data has been written to the buffer that you provide (the function won't always completely fill the buffer that you provide).

## See also

* [About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/win32/WinHttp/about-winhttp)
* [WinHTTP versions](https://learn.microsoft.com/windows/win32/WinHttp/winhttp-versions)
* [WinHttpCloseHandle](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpclosehandle)
* [WinHttpConnect](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpconnect)
* [WinHttpOpen](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopen)
* [WinHttpOpenRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopenrequest)
* [WinHttpQueryDataAvailable](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpquerydataavailable)
* [WinHttpReadDataEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpreaddataex)
* [WinHttpSendRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpsendrequest)
* [WinHttpWriteData](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpwritedata)