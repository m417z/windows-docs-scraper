# SetLastErrorEx function

## Description

Sets the last-error code.

Currently, this function is identical to the
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function. The second parameter is ignored.

## Parameters

### `dwErrCode` [in]

The last-error code for the thread.

### `dwType` [in]

This parameter is ignored.

## Remarks

The last-error code is kept in thread local storage so that multiple threads do not overwrite each other's values.

Most functions call
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) or **SetLastErrorEx** only when they fail. However, some system functions call
**SetLastError** or **SetLastErrorEx** under conditions of success; those cases are noted in each function's documentation.

Applications can optionally retrieve the value set by this function by using the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function immediately after a function fails.

Error codes are 32-bit values (bit 31 is the most significant bit). Bit 29 is reserved for application-defined error codes; no system error code has this bit set. If you are defining an error code for your application, set this bit to indicate that the error code has been defined by the application and to ensure that your error code does not conflict with any system-defined error codes.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/last-error-code)