# DrvSendPage function

## Description

A printer graphics DLL's **DrvSendPage** function is called by GDI when it has finished drawing a physical page, so the driver can send the page to the printer.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the drawing surface.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should call the Win32 **SetLastError** function to set an error code, and then return **FALSE**.

## Remarks

GDI calls **DrvSendPage** each time it has finished drawing a physical page's image on the drawing surface. The function is responsible for calling [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter) to send the image to the printer, and for performing end-of-page operations, such as ejecting the page.

[Printer graphics DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) using GDI-managed surfaces are typically implemented so that for pages that are banded, the image for each band is sent to the printer by the driver's [DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband) function.

Additionally, if a printer graphics DLL is using a [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/), the **DrvSendPage** function typically only needs to perform end-of-page operations, because the image is sent to the printer as it is drawn.

If there is a potential for this function to take a long time to execute, it should call [EngCheckAbort](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcheckabort) every five seconds. If **EngCheckAbort** returns **TRUE**, **DrvSendPage** should terminate its operation and return **FALSE**.

## See also

[DrvNextBand](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnextband)

[DrvStartPage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartpage)

[EngCheckAbort](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcheckabort)

[EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter)