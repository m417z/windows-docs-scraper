# _DEVQUERYPRINT_INFO structure

## Description

The DEVQUERYPRINT_INFO structure is used as an input parameter to a printer interface DLL's [DevQueryPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-devqueryprintex) function.

## Members

### `cbSize`

Spooler-supplied size, in bytes, of the DEVQUERYPRINT_INFO structure.

### `Level`

Spooler-supplied level of the DEVQUERYPRINT_INFO structure. Currently, this member is always set to 1.

### `hPrinter`

Spooler-supplied printer handle.

### `pDevMode`

Spooler-supplied pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure describing printer characteristics required by the print job.

### `pszErrorStr`

Spooler-supplied pointer to a buffer to receive a NULL-terminated error text string, if the print job cannot be printed.

### `cchErrorStr`

Spooler-supplied size, in bytes, of the string buffer pointed to by **pszErrorStr**.

### `cchNeeded`

Driver-supplied length, in bytes, of the error string supplied in the buffer pointed to by **pszErrorStr**. If the string is too large to fit in the buffer, the string should be truncated, but the untruncated length should be specified here.

## See also

[DevQueryPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-devqueryprintex)