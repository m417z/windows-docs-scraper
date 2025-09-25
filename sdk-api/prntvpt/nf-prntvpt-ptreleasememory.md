# PTReleaseMemory function

## Description

Releases buffers associated with print tickets and print capabilities.

## Parameters

### `pBuffer` [in]

A pointer to a buffer allocated during a call to a print ticket API.

## Return value

If the operation succeeds, the return value is S_OK, otherwise the **HRESULT** contains an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Use this function to release the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) buffer returned by [PTConvertPrintTicketToDevMode](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptconvertprinttickettodevmode).

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)