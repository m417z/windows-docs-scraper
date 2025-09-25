# PTConvertDevModeToPrintTicket function

## Description

Converts a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure to a print ticket inside an [IStream](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation).

## Parameters

### `hProvider` [in]

A handle to an open print ticket provider. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or the [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

### `cbDevmode`

The size of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) in bytes.

### `pDevmode` [in]

A pointer to the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea).

### `scope` [in]

A value that specifies the scope of *pPrintTicket*. This value can specify a single page, an entire document, or all documents in the print job. Settings in *pDevmode* that are outside the specified scope will not be included in *pPrintTicket*. See Remarks.

### `pPrintTicket`

A pointer to an [IStream](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation) with its seek position at the beginning of the print ticket.

## Return value

If the operation succeeds, the return value is S_OK, otherwise the **HRESULT** contains an error code.

If *hProvider* was opened in a different thread, the **HRESULT** is E_INVALIDARG.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

*hProvider* must be a handle that was opened in the same thread as the thread in which it is used for this function.

If the *pDevmode* points to a different printer, its settings may be lost and replaced with defaults.

Settings in *pDevmode* that are outside the *scope* are not included in *pPrintTicket*. For example, if the scope is a single page, then job-wide settings and document-wide settings are not included. A job scope includes document scope and page scope. A document scope includes page scope.

**PTConvertDevModeToPrintTicket** writes the print ticket to the [IStream](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation) referenced by *pPrintTicket* starting at the stream's current seek point. After **PTConvertDevModeToPrintTicket** returns, the caller must reset the seek point to the initial seek point to read the print ticket returned by the function.

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)