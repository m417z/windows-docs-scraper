# _PRINTPROCESSOROPENDATA structure

## Description

The PRINTPROCESSOROPENDATA structure is used as an input parameter to a print processor's [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor) function.

## Members

### `pDevMode`

Spooler-supplied pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `pDatatype`

Spooler-supplied pointer to a string representing the print job's data type.

### `pParameters`

Spooler-supplied pointer to a parameter string, as specified in a JOB_INFO_2 structure supplied to a call to the **SetJob** function, described in the Microsoft Windows SDK documentation.

### `pDocumentName`

Spooler-supplied pointer to a string representing the name of the input document associated with the print job.

### `JobId`

Spooler-supplied value identifying the print job.

### `pOutputFile`

Spooler-supplied pointer to a string representing the name of the output spool file.

### `pPrinterName`

Spooler-supplied pointer to a string representing the name of the printer to be used.

## See also

[DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor)