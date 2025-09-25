# _MONITORINIT structure

## Description

The MONITORINIT structure is used as an input parameter to a print monitor's [InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2) function.

## Members

### `cbSize`

Size, in bytes, of the MONITORINIT structure.

### `hSpooler`

Spooler handle, for use as input to functions identified by the MONITORREG structure.

### `hckRegistryRoot`

Registry handle, for use as input to functions identified by the MONITORREG structure.

### `pMonitorReg`

Pointer to a [MONITORREG](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorreg) structure.

### `bLocal`

**TRUE** if the monitor is being called by a local node spooler. **FALSE** if the monitor is being called by a cluster spooler. (Monitors can usually ignore this member.)

### `pszServerName`

Caller-supplied pointer to a string representing a server name.

## See also

[InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2)

[MONITORREG](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorreg)