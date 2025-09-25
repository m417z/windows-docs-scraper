# DrvStartPage function

## Description

The **DrvStartPage** function is called by GDI when it is ready to start sending the contents of a physical page to the driver for rendering.

## Parameters

### `pso` [in]

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should call the Win32 **SetLastError** function to set an error code, and then return **FALSE**.

## Remarks

A [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) must provide a **DrvStartPage** function. The function is called before each physical page of a print job is rendered. (A physical page can contain one or more document pages.)

Typically the function is used for sending control sequences to printer hardware, before a page is printed, by calling GDI's [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter) function. The function can also perform internal, page-specific initialization operations for the printer graphics DLL.

## See also

[DrvSendPage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsendpage)

[EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter)