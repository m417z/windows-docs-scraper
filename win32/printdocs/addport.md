# AddPort function

The **AddPort** function adds the name of a port to the list of supported ports. The **AddPort** function is exported by the port monitor.

## Parameters

*pName* \[in\]

A pointer to a zero-terminated string that specifies the name of the server to which the port is connected. If this parameter is **NULL**, the port is local.

*hWnd* \[in\]

A handle to the parent window of the **AddPort** dialog box.

*pMonitorName* \[in\]

A pointer to a zero-terminated string that specifies the monitor associated with the port.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The **AddPort** function browses the network to find existing ports, and displays a dialog box for the user. The **AddPort** function should validate the port name entered by the user by calling [**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports) to ensure that no duplicate names exist.

The caller of the **AddPort** function must have SERVER\_ACCESS\_ADMINISTER access to the server to which the port is connected.

To add a port without displaying a dialog box, call the **XcvData** function instead of **AddPort**. For more information about **XcvData**, see the Microsoft Windows Driver Development Kit (DDK).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **AddPortW** (Unicode) and **AddPortA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePort**](https://learn.microsoft.com/windows/win32/printdocs/deleteport)

[**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports)

[**SetPort**](https://learn.microsoft.com/windows/win32/printdocs/setport)

