## Description

A driver that supports USB4 returns information in a **DXGK_CONNECTION_USB4_INFO** structure when a new monitor connected over USB4 arrives.

## Members

### `Dpcd_DP_IN_Adapter_Number`

Uniquely identifies the DisplayPort-IN adapter on the USB4 device.

### `Dpcd_USB4_Driver_ID`

Uniquely identifies the host router in the system.

### `Dpcd_USB4_ROUTER_TOPOLOGY_ID[5]`

Uniquely identifies the USB4 device in the host router domain.

## Remarks

See [Supporting DisplayPort monitors over USB4 in KMD](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-usb4) for more information.

## See also

[**DXGKARG_QUERYCONNECTIONCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryconnectionchange)