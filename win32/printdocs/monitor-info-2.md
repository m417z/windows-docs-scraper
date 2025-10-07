# MONITOR\_INFO\_2 structure

The **MONITOR\_INFO\_2** structure identifies a monitor.

## Members

**pName**

A pointer to a null-terminated string that is the name of the monitor.

**pEnvironment**

A pointer to a null-terminated string that specifies the environment for which the monitor was written (for example, Windows NT x86, Windows IA64, Windows x64).

**pDLLName**

A pointer to a null-terminated string that is the name of the monitor DLL.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_MONITOR\_INFO\_2W** (Unicode) and **\_MONITOR\_INFO\_2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddMonitor**](https://learn.microsoft.com/windows/win32/printdocs/addmonitor)

[**EnumMonitors**](https://learn.microsoft.com/windows/win32/printdocs/enummonitors)

[**MONITOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-1)

