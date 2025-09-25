## Description

The **GdiGetSpoolFileHandle** function returns a handle to a print job's EMF file.

## Parameters

### `pwszPrinterName`

Caller-supplied pointer to a string representing the name of the target printer. See the following Remarks section.

### `pDevmode`

Caller-supplied pointer to a [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. See the following Remarks section.

### `pwszDocName`

Caller-supplied pointer to the print job's document name. See the following Remarks section.

## Return value

If the operation succeeds, the function returns a spool file handle. Otherwise the function returns **NULL**.

## Remarks

The **GdiGetSpoolFileHandle** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

When a print processor calls **GdiGetSpoolFileHandle**, it should supply arguments as illustrated in the following table.

| Parameter | Argument |
|---|---|
| *pwszPrinterName* | Pointer to the printer name received by the print processor's [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor) function. |
| *pDevmode* | Pointer to the [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure contained in the [**PRINTPROCESSOROPENDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprocessoropendata) structure, received by the print processor's [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor) function. |
| *pwszDocName* | Document name pointer received by the print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function. |

A print processor must call the **GdiGetSpoolFileHandle** function before calling any other GDI printing functions, because the returned handle must be passed to the other functions. The function calls OpenPrinter to open a connection to the printer, and CreateDC to create a device context for drawing. The print processor can obtain the device context's handle by calling [GdiGetDC](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetdc).

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiDeleteSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdideletespoolfilehandle)