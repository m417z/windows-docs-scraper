# DeletePrinterDriverPackage function

Deletes a printer driver package from the driver store.

## Parameters

*pszServer* \[in\]

A pointer to a constant, null-terminated string that specifies the name of the print server from which the driver package is being deleted. A **NULL** pointer value means the local computer.

*pszInfPath* \[in\]

A pointer to a constant, null-terminated string that specifies the path to the driver's \*.inf file.

*pszEnvironment* \[in\]

A pointer to a constant, null-terminated string that specifies the processor architecture (for example, Windows NT x86). This can be **NULL**.

## Return value

S\_OK, if the operation succeeds.

E\_ACCESSDENIED, if the package was shipped with Windows.

HRESULT\_CODE(ERROR\_PRINT\_DRIVER\_PACKAGE\_IN\_USE), if the package is being used.

Otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The driver store is typically %windir%\\inf or %windir%\\System32\\DriverStore\\FileRepository.

A driver package that shipped with Windows cannot be removed with this function.

The user must have printer administration privileges.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **DeletePrinterDriverPackageW** (Unicode) and **DeletePrinterDriverPackageA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

