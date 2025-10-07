# ConvertDevModeToPrintTicketThunk2 function

\[This function is not supported and might be disabled or deleted in future versions of Windows. [**PTConvertDevModeToPrintTicket**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptconvertdevmodetoprintticket) provides equivalent functionality and should be used instead.\]

Converts a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure to a print ticket.

## Parameters

*hProvider* \[in\]

A handle to an open print ticket provider. This handle is returned by the [**BindPTProviderThunk**](https://learn.microsoft.com/windows/win32/printdocs/bindptproviderthunk) function.

*pDevmode* \[in\]

A pointer to the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) to convert.

*cbSize* \[in\]

The size, in bytes, of the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) passed in *pDevmode*.

*scope* \[in\]

A value that specifies the scope of *ppPrintTicket*. This value can specify a single page, an entire document, or all documents in the print job. The value of this parameter must be a member of the [**EPrintTicketScope**](https://learn.microsoft.com/windows/desktop/api/prntvpt/ne-prntvpt-eprintticketscope) enumeration, cast as a **DWORD**.

*ppPrintTicket* \[out\]

The address of the buffer that contains a print ticket that represents the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) passed in *pDevmode*. This function calls [**CoTaskMemAlloc**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate this buffer. When the buffer is no longer needed, the caller must free it by calling [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

*pcbPrintTicketLength* \[out\]

The size, in bytes, of the print ticket returned in *ppPrintTicket*.

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

[**PTConvertDevModeToPrintTicket**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptconvertdevmodetoprintticket)

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

