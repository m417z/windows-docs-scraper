# _DOT11_CURRENT_OPERATION_MODE structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_CURRENT_OPERATION_MODE structure defines the current Native 802.11 operation mode on the
instance of a miniport driver that manages a wireless LAN (WLAN) adapter.

## Members

### `uReserved`

This member is reserved. The miniport driver must not modify the value of this member.

### `uCurrentOpMode`

A bitmask of the miniport driver's current operation modes. This bitmask is defined through the
following:

#### DOT11_OPERATION_MODE_EXTENSIBLE_AP

Specifies that the miniport driver supports the Extensible Access Point (ExtAP) operation
mode.

This value is available starting with Windows 7.

#### DOT11_OPERATION_MODE_EXTENSIBLE_STATION

Specifies that the miniport driver supports the Extensible Station (ExtSTA) operation
mode.

#### DOT11_OPERATION_MODE_NETWORK_MONITOR

Specifies that the miniport driver supports the Network Monitor (NetMon) operation mode.

#### DOT11_OPERATION_MODE_WFD_DEVICE

Specifies that the miniport driver supports the Wi-Fi Direct Device operation mode. This mode is available starting in Windows 8.

#### DOT11_OPERATION_MODE_WFD_GROUP_OWNER

Specifies that the miniport driver supports the Wi-Fi Direct Group Owner operation mode.This mode is available starting in Windows 8.

#### DOT11_OPERATION_MODE_WFD_CLIENT

Specifies that the miniport driver supports the Wi-Fi Direct Client operation mode. This mode is available starting in Windows 8.

For more information about operation modes, see
[Native 802.11 Operation
Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes).

## Syntax

```cpp
typedef struct _DOT11_CURRENT_OPERATION_MODE {
  ULONG uReserved;
  ULONG uCurrentOpMode;
} DOT11_CURRENT_OPERATION_MODE, *PDOT11_CURRENT_OPERATION_MODE;
```

## Remarks

The miniport driver must specify only one operation mode in the
**uCurrentOpMode** member.

For more information about Native 802.11 operation modes, see
[Native 802.11 Operation
Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes).

## See also

[DOT11_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_adapter)

[Native 802.11 Operation Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes)

[OID_DOT11_CURRENT_OPERATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-current-operation-mode)