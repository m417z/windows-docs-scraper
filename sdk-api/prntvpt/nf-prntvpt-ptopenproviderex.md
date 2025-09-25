# PTOpenProviderEx function

## Description

Opens an instance of a print ticket provider.

## Parameters

### `pszPrinterName` [in]

A pointer to the full name of a print queue.

### `dwMaxVersion`

The latest version of the [Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema) that the caller supports.

### `dwPrefVersion`

The version of the Print Schema requested by the caller.

### `phProvider` [out]

A pointer to a handle for the provider.

### `pUsedVersion` [out]

A pointer to the version of the Print Schema that the print ticket provider will use.

## Return value

If the operation succeeds, the return value is S_OK, otherwise the **HRESULT** contains an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The *pszPrinterName* parameter must be the full name, not the truncated name as it may appear in a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea).

The first version of the Print Schema was released with Windows Vista and is version 1. If the print ticket provider does not support *prefVersion*, **PTOpenProviderEx** successfully opens a handle and returns an earlier version in *usedVersion*.

To avoid a resource leak, *phProvider* must be closed with [PTCloseProvider](https://learn.microsoft.com/windows/desktop/api/prntvpt/nf-prntvpt-ptcloseprovider).

## See also

[Print Schema](https://learn.microsoft.com/windows/desktop/printdocs/printschema)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)