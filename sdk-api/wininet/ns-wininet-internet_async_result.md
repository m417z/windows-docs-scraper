# INTERNET_ASYNC_RESULT structure

## Description

Contains the result of a call to an asynchronous function. This structure is used with
[InternetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-internet_status_callback).

## Members

### `dwResult`

Result. This parameter can be an
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle, unsigned long integer, or Boolean return code from an asynchronous function.

### `dwError`

Error code, if
**dwResult** indicates that the function failed. If the operation succeeded, this member usually contains ERROR_SUCCESS.

## Remarks

The value of
**dwResult** is determined by the value of
*dwInternetStatus* in the status callback function.

| Value of *dwInternetStatus* | Value of **dwResult** |
| --- | --- |
| INTERNET_STATUS_HANDLE_CREATED | Pointer to the [HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle |
| INTERNET_STATUS_REQUEST_COMPLETE | Boolean return code from the asynchronous function. |

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

 [Asynchronous Operation](https://learn.microsoft.com/windows/desktop/WinInet/asynchronous-operation)