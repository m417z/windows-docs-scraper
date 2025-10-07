# GetPrinterDriverPackagePath function

Retrieves the path to the specified printer driver package on a print server.

## Parameters

*pszServer* \[in\]

A pointer to a constant, null-terminated string that specifies the name of the print server. Use **NULL** for the local computer.

*pszEnvironment* \[in\]

A pointer to a constant, null-terminated string that specifies the processor architecture (for example, Windows NT x86). This can be **NULL**.

*pszLanguage* \[in\]

A pointer to a constant, null-terminated string that specifies the [Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) language for the driver being installed. This can be **NULL**.

*pszPackageID* \[in\]

A pointer to a constant, null-terminated string that specifies the ID of the driver package.

*pszDriverPackageCab* \[in, out\]

A pointer to a null-terminated string that specifies the path to the cabinet file for the driver package. This can be **NULL**. See Remarks.

*cchDriverPackageCab* \[in\]

The size, in characters, of the *pszDriverPackageCab* buffer. This can be **NULL**.

*pcchRequiredSize* \[out\]

A pointer to the required size of the *pszDriverPackageCab* buffer.

## Return value

If the operation succeeds, the return value is S\_OK, otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

To obtain a value for *cchDriverPackageCab*, call the function with **NULL** as the value of *pszDriverPackageCab*. Use the value returned in *pcchRequiredSize* as the value of *cchDriverPackageCab* and call the function again.

The *pszPackageID* is typically obtained from a call to [**GetCorePrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/getcoreprinterdrivers).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **GetPrinterDriverPackagePathW** (Unicode) and **GetPrinterDriverPackagePathA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

