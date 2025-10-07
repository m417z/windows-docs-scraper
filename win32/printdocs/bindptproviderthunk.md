# BindPTProviderThunk function

\[This function is not supported and might be disabled or deleted in future versions of Windows. [**PTOpenProviderEx**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) provides equivalent functionality and should be used instead.\]

Opens an instance of a print ticket provider.

## Parameters

*pszPrinterName* \[in\]

The full name of a print queue.

*maxVersion* \[in\]

The latest version of the [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema) that the caller supports.

*prefVersion* \[in\]

The version of the [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema) requested by the caller.

*phProvider* \[out\]

A pointer to a handle to the print ticket provider.

*usedVersion* \[out\]

The version of the [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema) that the print ticket provider will use.

## Return value

If the method succeeds, it returns **S\_OK**; otherwise, it returns an **HRESULT** error code. For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

Before calling this function, the calling thread must initialize COM by calling [**CoInitializeEx**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Prntvpt.dll |

## See also

[Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema)

[**PTOpenProviderEx**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex)

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

