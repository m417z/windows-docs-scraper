# MergeAndValidatePrintTicketThunk2 function

\[This function is not supported and might be disabled or deleted in future versions of Windows. [**PTMergeAndValidatePrintTicket**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptmergeandvalidateprintticket) provides equivalent functionality and should be used instead.\]

Merges two print tickets and returns a valid, viable print ticket.

## Parameters

*hProvider* \[in\]

A handle to an open print ticket provider. This handle is returned by the [**BindPTProviderThunk**](https://learn.microsoft.com/windows/win32/printdocs/bindptproviderthunk) function.

*pBasePrintTicket* \[in\]

The buffer that contains the base print ticket data, expressed in XML as described in the [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema).

*basePrintTicketLength* \[in\]

The size, in bytes, of the buffer referenced by *pBasePrintTicket*.

*pDeltaPrintTicket* \[in, optional\]

The buffer that contains the print ticket to merge. The print ticket data is expressed in XML as described in the [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema). The value of this parameter can be **NULL**.

*deltaPrintTicketLength* \[in\]

The size, in bytes, of the buffer referenced by *pDeltaPrintTicket*.

*scope* \[in\]

The value that specifies whether the scope of *pDeltaPrintTicket* and *ppValidatedPrintTicket* is a single page, an entire document, or all documents in the print job. The value of this parameter must be a member of the [**EPrintTicketScope**](https://learn.microsoft.com/windows/desktop/api/prntvpt/ne-prntvpt-eprintticketscope) enumeration, cast as a **DWORD**.

*ppValidatedPrintTicket* \[out\]

The address of the buffer that contains the merged and validated print ticket. This function calls [**CoTaskMemAlloc**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate this buffer. When the buffer is no longer needed, the caller must free it by calling [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

*pValidatedPrintTicketLength* \[out\]

The size, in bytes, of the buffer referenced by *ppValidatedPrintTicket*.

*pbstrErrorMessage* \[out, optional\]

A pointer to a string that specifies what, if anything, is invalid about the print ticket in *pBasePrintTicket* or *pDeltaPrintTicket*. If they are both valid, this value is **NULL**. If *pbstrErrorMessage* is not **NULL** when the function returns, the caller must free the string with [**SysFreeString**](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

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

[**PTMergeAndValidatePrintTicket**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptmergeandvalidateprintticket)

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

