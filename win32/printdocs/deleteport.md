# DeletePort function

The **DeletePort** function displays a dialog box that allows the user to delete a port name.

## Parameters

*pName* \[in\]

A pointer to a zero-terminated string that specifies the name of the server for which the port should be deleted. If this parameter is **NULL**, a local port is deleted.

*hWnd* \[in\]

A handle to the parent window of the port-deletion dialog box.

*pPortName* \[in\]

A pointer to a zero-terminated string that specifies the name of the port that should be deleted.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

An application can retrieve the names of valid ports by calling the [**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports) function.

The **DeletePort** function returns an error if a printer is currently connected to the specified port.

The caller of the **DeletePort** function must have SERVER\_ACCESS\_ADMINISTER access to the server to which the port is connected.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **DeletePortW** (Unicode) and **DeletePortA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPort**](https://learn.microsoft.com/windows/win32/printdocs/addport)

[**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports)

