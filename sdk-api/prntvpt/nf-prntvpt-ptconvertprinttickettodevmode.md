# PTConvertPrintTicketToDevMode function

## Description

Converts a print ticket into a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure.

## Parameters

### `hProvider` [in]

A handle to an opened print ticket provider. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or the [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

### `pPrintTicket` [in]

A pointer to an [IStream](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation) with its seek position at the beginning of the print ticket.

### `baseDevmodeType`

A value indicating whether the user's default [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) or the print queue's default **DEVMODE** is used to provide values to the output **DEVMODE** when *pPrintTicket* does not specify every possible setting for a **DEVMODE**.

### `scope` [in]

A value that specifies the scope of *pPrintTicket*. This value can specify a single page, an entire document, or all documents in the print job. Settings in *pPrintTicket* that are outside of the specified scope are ignored. See Remarks.

### `pcbDevmode` [out]

A pointer to the size of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) in bytes.

### `ppDevmode` [out]

A pointer to the newly created [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea).

### `pbstrErrorMessage` [out]

A pointer to a string that specifies what, if anything, is invalid about *pPrintTicket*. If it is valid, this is **NULL**.

## Return value

If the operation succeeds, the return value is S_OK.

If *hProvider* was opened in a different thread, the **HRESULT** is E_INVALIDARG.

If *pPrintTicket* is invalid, the **HRESULT** is E_PRINTTICKET_FORMAT.

Otherwise, some other error code is returned in the **HRESULT**. For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The *hProvider* parameter must be a handle that was opened in the same thread as the thread in which it is used for this function.

If *baseDevmodeType* is kUserDefaultDevmode, but the user's default is not available, then the device's default will be used.

The returned [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) may be internally inconsistent or conflict with hard printer settings even though each setting within it is viable individually. For example, if the printer supports an optional duplexer but the *pPrintTicket* calls for duplexing, then the returned **DEVMODE** will also call for duplexing, even if the duplexer is not installed. Use [DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties) to correct the returned **DEVMODE**.

The buffer in the returned *ppDevmode* should be released with [PTReleaseMemory](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptreleasememory).

Values of *pPrintTicket* that are outside of the *scope* are ignored. For example, if the scope is only a single page, then job-wide settings and document-wide settings are ignored. Job scope includes document scope and page scope. Document scope includes page scope.

If *pbstrErrorMessage* is not **NULL** when the function returns, the caller must free the string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)