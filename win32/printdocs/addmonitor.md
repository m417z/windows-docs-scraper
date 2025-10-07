# AddMonitor function

The **AddMonitor** function installs a local port monitor and links the configuration, data, and monitor files.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the monitor should be installed. For systems that support only local installation of monitors, this string should be **NULL**.

*Level* \[in\]

The version of the structure to which *pMonitors* points. This value must be 2.

*pMonitors* \[in\]

A pointer to a [**MONITOR\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-2) structure. If the **pEnvironment** member of the *pMonitors* structure is **NULL**, the current environment of the caller (client), not of the destination (server), is used.

Note that the call will fail if the environment does not match the environment of the server, that is, you can only add a monitor that was written for the architecture of the server.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The caller must have the [SeLoadDriverPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

Before an application calls the **AddMonitor** function, all files required by the monitor must be copied to the SYSTEM32 directory.

To determine the port monitors that are currently installed, call the [**EnumMonitors**](https://learn.microsoft.com/windows/win32/printdocs/enummonitors) function.

To remove a monitor added by **AddMonitor**, call the [**DeleteMonitor**](https://learn.microsoft.com/windows/win32/printdocs/deletemonitor) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddMonitorW** (Unicode) and **AddMonitorA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeleteMonitor**](https://learn.microsoft.com/windows/win32/printdocs/deletemonitor)

[**EnumMonitors**](https://learn.microsoft.com/windows/win32/printdocs/enummonitors)

[**MONITOR\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-2)

