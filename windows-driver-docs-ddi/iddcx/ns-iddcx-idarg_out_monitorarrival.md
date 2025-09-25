# IDARG_OUT_MONITORARRIVAL structure

## Description

Gives information about the monitor that is exposed to the OS.

## Members

### `OsAdapterLuid`

 LUID of the adapter where this monitor is exposed to the OS
.

**Note** There are no API/DDI calls the driver can make with this information. Its only use is to pass it to companion applications so they can identify the monitor they control.

### `OsTargetId`

 DMM VidPn target id of the target this monitor is exposed to the OS.

**Note** There are no API/DDI calls the driver can make with this information. Its only use is to pass it to companion applications so they can identify the monitor they control.

**Note** Although this value is related to the [IDDCX_MONITOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_info) value **ConnectorIndex** passed by the driver, the OS will perform internal mapping between the two that will change in future release. As such, the driver should not take any dependencies on this mapping and should use **OsAdapterLuid** & **OsTargetId** instead.

## See also

[IDDCX_MONITOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_info)