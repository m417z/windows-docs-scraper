# InternetSetFilePointer function

## Description

Sets a file position for
[InternetReadFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfile). This is a synchronous call; however, subsequent calls to
[InternetReadFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfile) might block or return pending if the data is not available from the cache and the server does not support random access.

## Parameters

### `hFile` [in]

Handle returned from a previous call to
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla) (on an HTTP or HTTPS
URL) or
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) (using the GET or HEAD HTTP verb and passed to
[HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta) or
[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa)). This handle must not have been created with the
[INTERNET_FLAG_DONT_CACHE](https://learn.microsoft.com/windows/desktop/WinInet/api-flags) or
[INTERNET_FLAG_NO_CACHE_WRITE](https://learn.microsoft.com/windows/desktop/WinInet/api-flags) value set.

### `lDistanceToMove` [in]

The low order 32-bits of a signed 64-bit number of bytes to move the file pointer. **Internet Explorer 7 and earlier:** **InternetSetFilePointer** used to move the pointer only within the bounds of a LONG. When calling this older version of the function, *lpDistanceToMoveHigh* is reserved and should be set to **0**. A positive value moves the pointer forward in the file; a negative value moves it backward.

### `lpDistanceToMoveHigh` [in, out]

A pointer to the high order 32-bits of the signed 64-bit distance to move. If you do not need the high order 32-bits, this pointer must be set to **NULL**. When not **NULL**, this parameter also receives the high order DWORD of the new value of the file pointer. A positive value moves the pointer forward in the file; a negative value moves it backward.**Internet Explorer 7 and earlier:** **InternetSetFilePointer** used to move the pointer only within the bounds of a LONG. When calling this older version of the function, *lpDistanceToMoveHigh* is reserved and should be set to **0**.

### `dwMoveMethod` [in]

Starting point for the file pointer move. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| FILE_BEGIN | Starting point is zero or the beginning of the file. If FILE_BEGIN is specified, *lDistanceToMove* is interpreted as an unsigned location for the new file pointer. |
| FILE_CURRENT | Current value of the file pointer is the starting point. |
| FILE_END | Current end-of-file position is the starting point. This method fails if the content length is unknown. |

### `dwContext` [in]

This parameter is reserved and must be 0.

## Return value

I the function succeeds, it returns the current file position. A return value of **INVALID_SET_FILE_POINTER** indicates a potential failure and needs to be followed by be a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Since **INVALID_SET_FILE_POINTER** is a valid value for the low-order DWORD of the new file pointer, the caller must check both the
return value of the function and the error code returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine whether or not an error has occurred. If an error has occurred, the return value of InternetSetFilePointer is **INVALID_SET_FILE_POINTER** and **GetLastError** returns a value other than **NO_ERROR**.

If the function succeeds and *lpDistanceToMoveHigh* is **NULL**, the return value is the low-order **DWORD** of the new file pointer.

Note that if the function returns a value other than **INVALID_SET_FILE_POINTER**, the call to **InternetSetFilePointer** has succeeded and there is no need to call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function succeeds and *lpDistanceToMoveHigh* is not **NULL**, the return value is the lower-order **DWORD** of the new file pointer and *lpDistanceToMoveHigh* contains the high order **DWORD** of the new file pointer.

If a new file pointer is a negative value, the function fails, the file pointer is not moved, and the code returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is **ERROR_NEGATIVE_SEEK**.

If *lpDistanceToMoveHigh* is **NULL** and the new file position does not fit in a 32-bit value the function fails and returns **INVALID_SET_FILE_POINTER**.

## Remarks

This function cannot be used once the end of the file has been reached by
[InternetReadFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfile).

For
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handles created by
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) and sent by
[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa), a call to
[HttpEndRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpendrequesta) must be made on the handle before
**InternetSetFilePointer** is used.

**InternetSetFilePointer** cannot be used reliably if the content length is unknown.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**InternetSetFilePointer** has changed over time. In Internet Explorer 7 and earlier, it used to move the pointer only within the bounds of a LONG. When calling this older version of the function, *lDistanceToMove* contains the entire value. A positive value moves the pointer forward in the file; a negative value moves it backward. *lpDistanceToMoveHigh* is reserved and is set to **0**. In current versions, *lpDistanceToMoveHigh* is a significant value and where any negative value would be indicated.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)