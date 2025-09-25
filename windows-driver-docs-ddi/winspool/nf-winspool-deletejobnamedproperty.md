# DeleteJobNamedProperty function

## Description

Deletes the named property for the specified print job on the specified printer.

## Parameters

### `hPrinter` [in]

A handle to the printer object of interest. Use the [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter), [OpenPrinter2](https://learn.microsoft.com/windows/win32/printdocs/openprinter2), or the [AddPrinter](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

### `JobId` [in]

Identifier that specifies the print job. You obtain a print job identifier by calling the [AddJob](https://learn.microsoft.com/windows/win32/printdocs/addjob) function or the [StartDoc](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nf-printoem-oemstartdoc) function.

### `pszName` [in]

Name of the property that will be deleted.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS.**