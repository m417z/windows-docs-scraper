# DrvEndDoc function

## Description

The **DrvEndDoc** function is called by GDI when it has finished sending a document to the driver for rendering.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure.

### `fl` [in]

Caller-supplied set of bit flags. The following flag is defined:

| Flag | Definition |
| --- | --- |
| ED_ABORTDOC | The print job is being terminated before completion. |

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should call **SetLastError** to set an error code, and then return **FALSE**.

## Remarks

A [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) must provide a **DrvEndDoc** function. The function is called after the last physical page of a print job has been rendered.

Typically the function is used for sending control sequences to printer hardware, after a document has been printed, by calling GDI's [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter) function. The function can also perform internal, document-specific clean-up operations for the printer graphics DLL.

Because there is not a separate call into the printer graphics DLL when a print job is finished, the **DrvEndDoc** function must also send control sequences to the printer to end the job, if required by the printer. (In other words, there is one document per job.)

## See also

[DrvStartDoc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartdoc)