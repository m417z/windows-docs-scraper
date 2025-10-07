# GetCorePrinterDrivers function

Retrieves GUID, version, and date of the specified core printer drivers and the path to their packages.

## Parameters

*pszServer* \[in\]

A pointer to a constant, null-terminated string that specifies the name of the print server. Use **NULL** for the local computer.

*pszEnvironment* \[in\]

A pointer to a constant, null-terminated string that specifies the processor architecture (for example, Windows NT x86). This can be **NULL**.

*pszzCoreDriverDependencies* \[in\]

A pointer to a null-terminated multi-string that specifies the GUIDs of the core printer drivers.

*cCorePrinterDrivers* \[in\]

The number of strings in *pszzCoreDriverDependencies*.

*pCorePrinterDrivers* \[out\]

A pointer to an array of one or more [**CORE\_PRINTER\_DRIVER**](https://learn.microsoft.com/windows/win32/printdocs/core-printer-driver) structures.

## Return value

If the operation succeeds, the return value is S\_OK, otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **GetCorePrinterDriversW** (Unicode) and **GetCorePrinterDriversA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

