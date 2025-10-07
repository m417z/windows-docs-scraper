# UnbindPTProviderThunk function

\[This function is not supported and might be disabled or deleted in future versions of Windows. [**PTCloseProvider**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptcloseprovider) provides equivalent functionality and should be used instead.\]

Closes a handle to a print ticket provider.

## Parameters

*hProvider* \[in\]

A handle to an open print ticket provider. This handle is returned by the [**BindPTProviderThunk**](https://learn.microsoft.com/windows/win32/printdocs/bindptproviderthunk) function.

## Return value

If the method succeeds, it returns **S\_OK**; otherwise, it returns an **HRESULT** error code. For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Prntvpt.dll |

## See also

[Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema)

[**PTCloseProvider**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptcloseprovider)

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

