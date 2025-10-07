# SetPort function

The **SetPort** function sets the status associated with a printer port.

## Parameters

*pName* \[in\]

Pointer to a zero-terminated string that specifies the name of the printer server to which the port is connected. Set this parameter to **NULL** if the port is on the local machine.

*pPortName* \[in\]

Pointer to a zero-terminated string that specifies the name of the printer port.

*dwLevel* \[in\]

Specifies the type of structure pointed to by the *pPortInfo* parameter.

This value must be 3, which corresponds to a [**PORT\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/port-info-3) data structure.

*pPortInfo* \[in\]

Pointer to a [**PORT\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/port-info-3) structure that contains the port status information to set.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The caller of the **SetPort** function must be executing as an Administrator. Additionally, if the caller is a Port Monitor or Language Monitor, it must call [**RevertToSelf**](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself) to cease impersonation before it calls **SetPort**.

All programs that call **SetPort** must have SERVER\_ACCESS\_ADMINISTER access to the server to which the port is connected.

When you set a printer port status value with the severity value PORT\_STATUS\_TYPE\_ERROR, the print spooler stops sending jobs to the port. The print spooler resumes sending jobs to the port when the port status is cleared by another call to **SetPort**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **SetPortW** (Unicode) and **SetPortA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**PORT\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/port-info-3)

