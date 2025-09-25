# SetLastError function

## Description

Sets the last-error code for the calling thread.

## Parameters

### `dwErrCode` [in]

The last-error code for the thread.

## Remarks

The last-error code is kept in thread local storage so that multiple threads do not overwrite each other's values.

Most functions call **SetLastError** or [SetLastErrorEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setlasterrorex) only when they fail. However, some system functions call **SetLastError** or **SetLastErrorEx** under conditions of success; those cases are noted in each function's documentation.

Applications can optionally retrieve the value set by this function by using the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function immediately after a function fails.

Error codes are 32-bit values (bit 31 is the most significant bit). Bit 29 is reserved for application-defined error codes; no system error code has this bit set. If you are defining an error code for your application, set this bit to indicate that the error code has been defined by your application and to ensure that your error code does not conflict with any system-defined error codes.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/win32/Debug/error-handling-functions)

[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[Last-Error Code](https://learn.microsoft.com/windows/win32/Debug/last-error-code)

[SetLastErrorEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setlasterrorex)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)