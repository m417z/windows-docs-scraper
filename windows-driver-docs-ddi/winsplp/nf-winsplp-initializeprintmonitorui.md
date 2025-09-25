# InitializePrintMonitorUI function

## Description

A port monitor UI DLL's **InitializePrintMonitorUI** function supplies the print spooler with addresses of DLL functions.

## Return value

The function should return a pointer to an initialized [MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui) structure.

## Remarks

Port monitor UI DLLs are required to export an **InitializePrintMonitorUI** function. The function is called immediately after the DLL is loaded, and is not called again until the DLL is reloaded. Its purposes are to allow the DLL to initialize itself, and to provide the spooler with pointers to internal functions.

## See also

[InitializePrintMonitor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor)

[MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui)