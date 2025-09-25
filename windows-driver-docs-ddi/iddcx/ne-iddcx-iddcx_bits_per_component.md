## Description

An **IDDCX_BITS_PER_COMPONENT** enumeration value identifies the supported or requested number of bits per color component for the dithering support of a target.

## Constants

### `IDDCX_BITS_PER_COMPONENT_NONE:0`

A driver can use this flag to indicate no support for a particular wire encoding format; for example, in calls to [**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info) or [**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes2). When it is used as an input in the driver, for example as part of a call to [**EVT_IDD_CX_ADAPTER_COMMIT_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes2), this value is never used.

### `IDDCX_BITS_PER_COMPONENT_6:0x1`

For driver reporting, indicates support for sending color component values using 6 bits. For driver information, indicates 6 bits per component should be sent to the monitor.

### `IDDCX_BITS_PER_COMPONENT_8:0x2`

For driver reporting, indicates support for sending color component values using 8 bits. For driver information, indicates 8 bits per component should be sent to the monitor.

### `IDDCX_BITS_PER_COMPONENT_10:0x4`

For driver reporting, indicates support for sending color component values using 10 bits. For driver information, indicates 10 bits per component should be sent to the monitor.

### `IDDCX_BITS_PER_COMPONENT_12:0x8`

For driver reporting, indicates support for sending color component values using 12 bits. For driver information, indicates 12 bits per component should be sent to the monitor.

### `IDDCX_BITS_PER_COMPONENT_14:0x10`

For driver reporting, indicates support for sending color component values using 14 bits. For driver information, indicates 14 bits per component should be sent to the monitor.

### `IDDCX_BITS_PER_COMPONENT_16:0x20`

For driver reporting, indicates support for sending color component values using 16 bits. For driver information, indicates 16 bits per component should be sent to the monitor.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info)

[**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes2)

[**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component)