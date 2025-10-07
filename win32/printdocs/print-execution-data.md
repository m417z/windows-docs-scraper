# PRINT\_EXECUTION\_DATA structure

Contains the execution context of the printer driver that calls [**GetPrintExecutionData**](https://learn.microsoft.com/windows/win32/printdocs/getprintexecutiondata).

## Members

**context**

The [**PRINT\_EXECUTION\_CONTEXT**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-context) value that represents the current execution context of the printer driver.

**clientAppPID**

If the value of **context** is **PRINT\_EXECUTION\_CONTEXT\_WOW64**, **clientAppPID** identifies the client application on whose behalf the splwow64.exe process loaded the printer driver. If the value of **context** is not **PRINT\_EXECUTION\_CONTEXT\_WOW64**, **clientAppPID** is zero.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[**GetPrintExecutionData**](https://learn.microsoft.com/windows/win32/printdocs/getprintexecutiondata)

[**PRINT\_EXECUTION\_CONTEXT**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-context)

