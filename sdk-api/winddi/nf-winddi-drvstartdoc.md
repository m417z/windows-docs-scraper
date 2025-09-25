# DrvStartDoc function

## Description

The **DrvStartDoc** function is called by GDI when it is ready to start sending a document to the driver for rendering.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure.

### `pwszDocName` [in]

Caller-supplied pointer to a NULL-terminated Unicode string specifying the name of the document to be printed.

### `dwJobId` [in]

Caller-supplied print job number. This value is returned to GDI from the spooler in a call to **StartDocPrinter**.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should call the Win32 **SetLastError** function to set an error code, and then return **FALSE**.

## Remarks

A [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) must provide a **DrvStartDoc** function. Typically the function is used for sending control sequences to printer hardware, before a document is printed, by calling GDI's [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter) function. The function can also perform internal, document-specific initialization operations for the printer graphics DLL.

The **DrvStartDoc** function is called at the start of a print job, and whenever an application (such as a print processor) calls **ResetDC** (see [DrvResetPDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvresetpdev)). When the call to **DrvStartDoc** comes from **ResetDC**, the *pwszDocName* parameter is set to **NULL** and the *dwJobId* parameter is set to zero. When the call comes from an application, these parameters are set, respectively, to the document name and the print job number.

Because there is not a separate call into the printer graphics DLL when a print job is started, the **DrvStartDoc** function must also send control sequences to the printer to initialize the job, if required by the printer. (In other words, there is one document per job.)

## See also

[DrvEndDoc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenddoc)

[DrvResetPDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvresetpdev)

[EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter)