## Description

> [!CAUTION]
> The **MONITOREX** structure is obsolete and supported for compatibility purposes only. New print monitors should the implement [InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2) function and [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure so that they can be used with print server clusters.

The **MONITOREX** structure is used as the return value for a print monitor's [InitializePrintMonitor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor) function.

## Members

### `dwMonitorSize`

Specifies the size, in bytes, of the Monitor **member**.

### `Monitor`

A [**MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor) structure.

## Remarks

Print monitors are responsible for filling in the **MONITOREX** and **MONITOR** structures.

## See also

[**MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor)