# ConfigurePort function

The **ConfigurePort** function displays the port-configuration dialog box for a port on the specified server.

## Parameters

*pName* \[in\]

Pointer to a null-terminated string that specifies the name of the server on which the specified port exists. If this parameter is **NULL**, the port is local.

*hWnd* \[in\]

Handle to the parent window of the port-configuration dialog box.

*pPortName* \[in\]

Pointer to a null-terminated string that specifies the name of the port to be configured.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Before calling the **ConfigurePort** function, an application should call the [**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports) function to determine valid port names.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **ConfigurePortW** (Unicode) and **ConfigurePortA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports)

