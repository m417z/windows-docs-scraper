# PRINT\_EXECUTION\_CONTEXT enumeration

Represents the execution context when [**GetPrintExecutionData**](https://learn.microsoft.com/windows/win32/printdocs/getprintexecutiondata) is called.

## Constants

**PRINT\_EXECUTION\_CONTEXT\_APPLICATION**

The caller is running in an application.

**PRINT\_EXECUTION\_CONTEXT\_SPOOLER\_SERVICE**

The caller is running in the spooler service (spoolsv.exe).

**PRINT\_EXECUTION\_CONTEXT\_SPOOLER\_ISOLATION\_HOST**

The caller is running in the print isolation host (PrintIsolationHost.exe)

**PRINT\_EXECUTION\_CONTEXT\_FILTER\_PIPELINE**

The caller is running in the print filter pipeline (printfilterpipelinesvc.exe)

**PRINT\_EXECUTION\_CONTEXT\_WOW64**

The caller is running in splwow64.exe

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[**GetPrintExecutionData**](https://learn.microsoft.com/windows/win32/printdocs/getprintexecutiondata)

[**PRINT\_EXECUTION\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/print-execution-data)

