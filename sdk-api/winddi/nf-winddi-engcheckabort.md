# EngCheckAbort function

## Description

The **EngCheckAbort** function enables a printer graphics DLL to determine if a print job should be terminated.

## Parameters

### `pso`

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure, previously received from GDI.

## Return value

If the print job should be terminated, the function returns **TRUE**. If the print job should not be terminated, or if *pso* does not point to a valid SURFOBJ structure, the function returns **FALSE**.

## Remarks

A [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) should call **EngCheckAbort** from within any graphics DDI function that takes more than five seconds to execute. If the print job should be terminated, the printer graphics DLL should stop its current operation and return to GDI, specifying a return value of **FALSE** for the graphics DDI function that called **EngCheckAbort**.