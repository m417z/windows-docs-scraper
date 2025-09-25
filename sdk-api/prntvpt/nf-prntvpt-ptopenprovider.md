# PTOpenProvider function

## Description

Opens an instance of a print ticket provider.

## Parameters

### `pszPrinterName` [in]

A pointer to the full name of a print queue.

### `dwVersion`

The version of the [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema) requested by the caller.

### `phProvider` [out]

A pointer to a handle for the provider.

## Return value

If the operation succeeds, the return value is S_OK, otherwise the **HRESULT** contains an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

*pszPrinterName* must be the full name, not the truncated name as it may appear in a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea).

The first version of the Print Schema was released with Windows Vista and is version 1. This operation fails if *version* is not supported. Contrast this with [PTOpenProviderEx](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptopenproviderex) which opens a provider even if it supports only versions that are earlier than requested.

To avoid a resource leak, *phProvider* must be closed with [PTCloseProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptcloseprovider).

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)