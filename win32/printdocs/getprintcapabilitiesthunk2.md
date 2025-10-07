# GetPrintCapabilitiesThunk2 function

\[This function is not supported and might be disabled or deleted in future versions of Windows. [**PTGetPrintCapabilities**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptgetprintcapabilities) provides equivalent functionality and should be used instead.\]

Retrieves the printer's capabilities formatted in compliance with the XML [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema).

## Parameters

*hProvider* \[in\]

A handle to an open print ticket provider. This handle is returned by the [**BindPTProviderThunk**](https://learn.microsoft.com/windows/win32/printdocs/bindptproviderthunk) function.

*pPrintTicket* \[in\]

The buffer that contains the print ticket data, expressed in XML as described in the [Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema).

*cbPrintTicket* \[in\]

The size, in bytes, of the buffer referenced by *pPrintTicket*.

*ppbPrintCapabilities* \[out\]

The address of the buffer that is allocated by this function and contains the valid print capabilities information, encoded as XML. This function calls [**CoTaskMemAlloc**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate this buffer. When the buffer is no longer needed, the caller must free it by calling [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

*pcbPrintCapabilitiesLength* \[out\]

The size, in bytes, of the buffer referenced by *ppbPrintCapabilities*.

*pbstrErrorMessage* \[out, optional\]

A pointer to a string that specifies what, if anything, is invalid about *pPrintTicket*. If it is valid, this value is **NULL**. If *pbstrErrorMessage* is not **NULL** when the function returns, the caller must free the string with [**SysFreeString**](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

## Return value

If the method succeeds, it returns **S\_OK**; otherwise, it returns an **HRESULT** error code. For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Prntvpt.dll |

## See also

[**PTGetPrintCapabilities**](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptgetprintcapabilities)

[Print Schema](https://learn.microsoft.com/windows/win32/printdocs/printschema)

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

