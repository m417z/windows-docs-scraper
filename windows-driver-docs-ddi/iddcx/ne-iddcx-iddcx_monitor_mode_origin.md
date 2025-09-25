# IDDCX_MONITOR_MODE_ORIGIN enumeration

## Description

A **IDDCX_MONITOR_MODE_ORIGIN** value describes a mode the monitor supports based on the monitor description.

## Constants

### `IDDCX_MONITOR_MODE_ORIGIN_UNINITIALIZED:0`

Indicates that an **IDDCX_MONITOR_MODE_ORIGIN** variable has not yet been assigned a meaningful value.

### `IDDCX_MONITOR_MODE_ORIGIN_MONITORDESCRIPTOR:1`

Indicates that the driver added this mode from directly processing the monitor description.

### `IDDCX_MONITOR_MODE_ORIGIN_DRIVER:2`

Indicates that the driver did not add this mode as a direct resolution of processing the modes/ supported by the monitor but because of separate additional knowledge it has about the monitor.

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description)

[**IDDCX_MONITOR_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_mode)