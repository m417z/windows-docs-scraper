# DXGKARG_QUERYCONNECTIONCHANGE structure

## Description

A **DXGKARG_QUERYCONNECTIONCHANGE** structure holds the arguments for [**DXGKDDI_QUERYCONNECTIONCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryconnectionchange).

## Members

### `ConnectionChange`

[out] A [**DXGK_CONNECTION_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_connection_change) structure into which the driver copies the oldest available connection change.

### `Usb4MonitorInfo`

[out] An OS-allocated [**DXGK_CONNECTION_USB4_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_connection_usb4_info) structure that the driver should complete if [**MonitorConnectFlags.Usb4DisplayPortMonitor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_connection_monitor_connect_flags) was set. Available starting in Windows 11 (WDDM 3.0). See [Supporting DisplayPort monitors over USB4 in KMD](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-usb4) for more information.

## See also

[**DXGKDDI_QUERYCONNECTIONCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryconnectionchange)