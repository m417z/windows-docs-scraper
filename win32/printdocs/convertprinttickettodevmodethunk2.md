# ConvertPrintTicketToDevModeThunk2 function

\[This function is not supported and might be disabled or deleted in future versions of Windows. [**PTConvertPrintTicketToDevMode**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptconvertprinttickettodevmode) provides equivalent functionality and should be used instead.\]

Converts a print ticket to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure.

## Parameters

*hProvider* \[in\]

A handle to an open print ticket provider. This handle is returned by the [**BindPTProviderThunk**](https://learn.microsoft.com/windows/win32/printdocs/bindptproviderthunk) function.

*pPrintTicket* \[in\]

The buffer that contains the print ticket to convert.

*cbSize* \[in\]

The size, in bytes, of the buffer passed in *pPrintTicket*.

*baseType* \[in\]

A value indicating whether the user's default [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) or the print queue's default **DEVMODE** is used to provide values to the output **DEVMODE** when *pPrintTicket* does not specify every possible setting for a **DEVMODE**. The value of this parameter must be a member of the [**EDefaultDevmodeType**](https://learn.microsoft.com/windows/win32/api/prntvpt/ne-prntvpt-edefaultdevmodetype) enumeration, cast as an **INT**.

*scope* \[in\]

A value that specifies the scope of *pPrintTicket*. This value can specify a single page, an entire document, or all documents in the print job. The value of this parameter must be a member of the [**EPrintTicketScope**](https://learn.microsoft.com/windows/desktop/api/prntvpt/ne-prntvpt-eprintticketscope) enumeration, cast as a **DWORD**.

*ppDevmode* \[out\]

The address of the newly created [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea). This function calls [**CoTaskMemAlloc**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate this buffer. When the buffer is no longer needed, the caller must free it by calling [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

*pcbDevModeLength* \[out\]

The size, in bytes, of the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) returned in *ppDevmode*.

*errMsg* \[out, optional\]

A pointer to a string that specifies what, if anything, is invalid about the print ticket in *pPrintTicket*. If it is valid, this is **NULL**. If *errMsg* is not **NULL** when the function returns, the caller must free the string with [**SysFreeString**](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

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

[**PTConvertPrintTicketToDevMode**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptconvertprinttickettodevmode)

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

