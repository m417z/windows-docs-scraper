# InitializePrintMonitor function

## Description

The **InitializePrintMonitor** function is obsolete and is supported only for compatibility purposes. New print monitors should implement [InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2) so that they can be used with print server clusters.

A print monitor's **InitializePrintMonitor** function initializes a print monitor.

## Parameters

### `pRegistryRoot` [in]

Caller-supplied pointer to a string identifying a registry path that the print monitor can use to store monitor-specific values.

## Return value

If the operation succeeds, the function should return a pointer to a [MONITOREX](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorex) structure. Otherwise the function should call SetLastError (described in the Microsoft Windows SDK documentation) to set an error code, and return **NULL**.

## Remarks

The **InitializePrintMonitor** function must be exported by [language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and by port monitor server DLLs. The function is called immediately after the monitor DLL is loaded, and is not called again until the DLL is reloaded. Its purposes are to allow the monitor to initialize itself, and to provide the spooler with pointers to internal monitor functions. Function pointers are contained in a [MONITOR](https://learn.microsoft.com/previous-versions/windows/hardware/modem/ff542552(v=vs.85)) structure, which is referenced through the [MONITOREX](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorex) function.

The *pRegistryRoot* parameter supplies a pointer a string representing the path to a *MonitorName* registry key, where *MonitorName* is the monitor name that was specified when the spooler's **AddMonitor** function was called to add the monitor. The monitor can use this key to store monitor-specific value names and values. When the spooler's **DeleteMonitor** function is called, the spooler deletes the *MonitorName* key and all values stored underneath it. (The **AddMonitor** and **DeleteMonitor** functions are described in the Windows SDK documentation.)

## See also

[InitializePrintMonitorUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitorui)

[MONITOREX](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorex)