# PTGetPrintCapabilities function

## Description

Retrieves the printer's capabilities formatted in compliance with the XML [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema).

## Parameters

### `hProvider` [in]

A handle to an open provider whose print capabilities are to be retrieved. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or the [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

### `pPrintTicket` [in]

A pointer to a stream with its seek position at the beginning of the print ticket content. This parameter can be **NULL**.

### `pCapabilities`

A pointer to the stream where the print capabilities will be written, starting at the current seek position.

### `pbstrErrorMessage` [out]

A pointer to a string that specifies what, if anything, is invalid about *pPrintTicket*. If it is valid, this value is **NULL**.

## Return value

If the operation succeeds, the return value is S_OK.

If *hProvider* was opened in a different thread, the **HRESULT** is E_INVALIDARG.

If the *pPrintTicket* is not compliant with the [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema) , the **HRESULT** is E_PRINTTICKET_FORMAT.

If the *pCapabilities* is not compliant with the [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema) , the **HRESULT** is E_PRINTCAPABILITIES_FORMAT.

If *hProvider* was opened in a different thread, the **HRESULT** is E_INVALIDARG.

Otherwise, another error code is returned in the **HRESULT**. For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

*hProvider* must be a handle that was opened in the same thread as the thread in which it is used for this function.

The printer driver uses *pPrintTicket* values (when the value is not **NULL**) to create settings when the driver produces printer capabilities that vary depending on the current settings.

When the function returns, the seek position of *pPrintTicket* is at the end of the print ticket content and the seek position of *pCapabilities* is at the end of the stream. If the caller uses a memory stream for *pCapabilities*, such as a stream created by [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) , the caller is responsible for resetting the seek position before reading the data.

If *pbstrErrorMessage* is not **NULL** when the function returns, the caller must free the string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)