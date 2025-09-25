# PTCloseProvider function

## Description

Closes a print ticket provider handle.

## Parameters

### `hProvider` [in]

A handle to the provider. This handle is returned by the [PTOpenProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenprovider) or [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) function.

## Return value

If the operation succeeds, the return value is S_OK, otherwise the **HRESULT** contains an error code.

If *hProvider* was opened in a different thread, the **HRESULT** is E_INVALIDARG.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The *hProvider* parameter must be a handle that was opened in the same thread as the thread in which it is used for this function.

A handle cannot be used after it is closed.

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)