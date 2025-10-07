# GetPrintExecutionData function

The **GetPrintExecutionData** retrieves the current print context.

> [!Note]
> This function is intended for use by printer drivers that are running in the context of the print spooler.

## Parameters

*pData* \[out\]

A pointer to a variable that receives the address of the [**PRINT\_EXECUTION\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-data) structure.

## Return value

Returns **TRUE** if the function succeeds; otherwise **FALSE**. If the return value is **FALSE**, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get the error status.

## Remarks

Printer drivers should call [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) on the winspool.drv module to get the address of the **GetPrintExecutionData** function because **GetPrintExecutionData** is not supported on Windows Vista or earlier versions of Windows.

**GetPrintExecutionData** only fails if the value of *pData* is **NULL**.

The value of the **clientAppPID** member of [**PRINT\_EXECUTION\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-data) is only meaningful if the value of **context** is **PRINT\_EXECUTION\_CONTEXT\_WOW64**. If the value of **context** is not **PRINT\_EXECUTION\_CONTEXT\_WOW64**, the value of **clientAppPID** is 0.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| DLL<br> | Winspool.drv |

## See also

[**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[**PRINT\_EXECUTION\_CONTEXT**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-context)

[**PRINT\_EXECUTION\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-data)

