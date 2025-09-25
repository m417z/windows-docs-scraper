# GetLastError function

## Description

Retrieves the calling thread's last-error code value. The last-error code is maintained on a per-thread basis. Multiple threads do not overwrite each other's last-error code.

**Visual Basic:** Applications should call **err.LastDllError** instead of **GetLastError**.

## Return value

The return value is the calling thread's last-error code.

The Return Value section of the documentation for each function that sets the last-error code notes the conditions under which the function sets the last-error code. Most functions that set the thread's last-error code set it when they fail. However, some functions also set the last-error code when they succeed. If the function is not documented to set the last-error code, the value returned by this function is simply the most recent last-error code to have been set; some functions set the last-error code to 0 on success and others do not.

## Remarks

Functions executed by the calling thread set this value by calling the [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) function. You should call the **GetLastError** function immediately when a function's return value indicates that such a call will return useful data. That is because some functions call **SetLastError** with a zero when they succeed, wiping out the error code set by the most recently failed function.

To obtain an error string for system error codes, use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function. For a complete list of error codes provided by the operating system, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

The error codes returned by a function are not part of the Windows API specification and can vary by operating system or device driver. For this reason, we cannot provide the complete list of error codes that can be returned by each function. There are also many functions whose documentation does not include even a partial list of error codes that can be returned.

Error codes are 32-bit values (bit 31 is the most significant bit). Bit 29 is reserved for application-defined error codes; no system error code has this bit set. If you are defining an error code for your application, set this bit to one. That indicates that the error code has been defined by an application, and ensures that your error code does not conflict with any error codes defined by the system.

To convert a system error into an **HRESULT** value, use the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/win32/api/winerror/nf-winerror-hresult_from_win32) macro.

#### Examples

For an example, see [Retrieving the Last-Error Code](https://learn.microsoft.com/windows/win32/Debug/retrieving-the-last-error-code).

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/win32/Debug/error-handling-functions)

[FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage)

[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/win32/api/winerror/nf-winerror-hresult_from_win32)

[Last-Error Code](https://learn.microsoft.com/windows/win32/Debug/last-error-code)

[SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror)

[SetLastErrorEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setlasterrorex)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)