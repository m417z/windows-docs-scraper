# PTMergeAndValidatePrintTicket function

## Description

Merges two print tickets and returns a valid, viable print ticket.

## Parameters

### `hProvider` [in]

A handle to an open print ticket provider. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or the [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

### `pBaseTicket` [in]

A pointer to a print ticket. The stream's seek position must be at the beginning of the print ticket content.

**Note** **PTMergeAndValidatePrintTicket** will validate the base ticket against the [Print Schema Framework](https://learn.microsoft.com/windows/desktop/printdocs/printschema) before merging.

### `pDeltaTicket` [in]

A pointer to a print ticket. The stream's seek position must be at the beginning of the print ticket content. **NULL** can be passed to this parameter. See Remarks.

**Note** **PTMergeAndValidatePrintTicket** will validate the delta ticket against the [Print Schema Framework](https://learn.microsoft.com/windows/desktop/printdocs/printschema) before merging.

### `scope` [in]

A value specifying whether the scope of *pDeltaTicket* and *pResultTicket* is a single page, an entire document, or all documents in the print job. See Remarks.

### `pResultTicket`

A pointer to the stream where the viable, merged ticket will be written. The seek position will be at the end of the print ticket. See Remarks.

### `pbstrErrorMessage` [out]

A pointer to a string that specifies what, if anything, is invalid about *pBaseTicket* or *pDeltaTicket*. If both are valid, this is **NULL**. Viability problems are not reported in *pbstrErrorMessage*.

## Return value

If the operation succeeds with no conflict between the settings of the merged ticket and the capabilities of the printer, the **HRESULT** is S_PT_NO_CONFLICT.

If the operation succeeds but the merged ticket had to be changed in one or more settings because it requested functionality that the printer does not support, the **HRESULT** is S_PT_CONFLICT_RESOLVED. See Remarks.

If *hProvider* was opened in a different thread, the **HRESULT** is E_INVALIDARG.

If *pBaseTicket* is invalid, the **HRESULT** is E_PRINTTICKET_FORMAT.

If *pDeltaTicket* is invalid, the **HRESULT** is E_DELTA_PRINTTICKET_FORMAT.

Otherwise, some other error code is returned in the **HRESULT**. For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

*hProvider* must be a handle that was opened in the same thread as the thread in which it is used for this function.

This function validates in two ways: It first validates both input tickets against the [Print Schema Framework](https://learn.microsoft.com/windows/desktop/printdocs/printschema), reporting errors in *pbstrErrorMessage*. It then checks the viability of the merged print ticket with the printer driver. If the merged ticket requests functionality that the printer does not support, the nonviable settings are replaced and the printer driver determines what substitute setting to use. Typically, the printer driver uses the user's default print ticket setting. If the printer driver does not use the same print ticket that *pBaseTicket* points to as the source for substitute values, it is possible that *pResultTicket* will differ in some settings from both of the input print tickets.

Typically, *pBaseTicket* contains a full range of job, document and page settings. Usually the user default or the device default print ticket is used for *pBaseTicket*.

If *pDeltaTicket* is **NULL**, the method validates *pBaseTicket*, checks its viability, and returns it, possibly modified, in the stream pointed to by *pResultTicket*.

Values of *pDeltaTicket* that are outside of the *scope* are ignored. For example, if the scope is only a single page, then job-wide settings and document-wide settings are ignored. Job scope includes document scope and page scope. Document scope includes page scope.

Settings that are outside of the *scope* are not included in the *pResultTicket*.

When the function returns a value, the seek position of *pResultTicket* is at the end of the print ticket content. The caller is responsible for resetting the seek position before reading the data.

If *pbstrErrorMessage* is not **NULL** when the function returns, the caller must free the string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)