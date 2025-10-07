# CorePrinterDriverInstalled function

The **CorePrinterDriverInstalled** function reports whether a core printer driver with a specified GUID, date, and version is installed.

## Parameters

*pszServer* \[in\]

Pointer to a constant, null-terminated string that specifies the name of the print server. Use **NULL** for the local computer.

*pszEnvironment* \[in\]

Pointer to a constant, null-terminated string that specifies the processor architecture (for example, Windows NT x86). This can be **NULL**.

*CoreDriverGUID* \[in\]

The GUID of the core printer driver.

*ftDriverDate* \[in\]

The date of the core printer driver.

*dwlDriverVersion* \[in\]

The version of the core printer driver.

*pbDriverInstalled* \[out\]

A pointer to **TRUE** if the driver, or a newer version, is installed, **FALSE** otherwise.

## Return value

If the operation succeeds, the return value is S\_OK, otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **CorePrinterDriverInstalledW** (Unicode) and **CorePrinterDriverInstalledA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

