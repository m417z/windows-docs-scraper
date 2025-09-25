## Description

The **DXGK_CONNECTION_MONITOR_CONNECT_FLAGS** structure specifies flags for the connected monitor.

## Members

### `Usb4DisplayPortMonitor`

The monitor is a USB4 connected monitor. See [Supporting DisplayPort monitors over USB4 in KMD](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-usb4) for more information.

### `DisplayMuxConnectionChange`

The **MonitorStatusConnected** or **MonitorStatusDisconnected** connection status is related to an automatic display switch. This flag should only be used during an automatic display switch sequence and not for any other purpose. For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

### `Reserved`

Reserved; do not use.

### `Value`

An alternative way to access the flags.

## See also

[**DXGK_CONNECTION_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_connection_change)

[**DxgiddiQueryConnectionChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryconnectionchange)