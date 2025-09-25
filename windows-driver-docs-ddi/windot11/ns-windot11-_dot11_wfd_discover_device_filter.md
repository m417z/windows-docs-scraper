# _DOT11_WFD_DISCOVER_DEVICE_FILTER structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_DISCOVER _DEVICE_FILTER** structure describes a P2P device and Group Owner filter when responding to OID_DOT11_WFD_DISCOVERY_REQUEST requests.

## Members

### `DeviceID`

The device address of a P2P Device or Group Owner to be discovered by the local P2P device.

### `ucBitmask`

Filters which instances of the P2P device to discover. Possible values include:

| Term | Description |
| --- | --- |
| DISCOVERY_FILTER_BITMASK_DEVICE | The local P2P device discovers the P2P device with the desired **DeviceID**. |
| DISCOVERY_FILTER_BITMASK_GO | The local P2P device discovers a group with P2P group ID matching the specified **DeviceID** and **GroupSSID**. |
| DISCOVERY_FILTER_BITMASK_ANY | The local P2P device needs only to discover the P2P device or any group owner hosted by the P2P device. |

### `GroupSSID`

If GroupSSID is not a zero-length SSID, this member specifies the SSID of a P2P group that the local P2P device discovers. If this is the P2P wildcard SSID ("DIRECT-"), the local P2P device discovers all groups with P2P Group ID matching the desired device ID.

## Syntax

```cpp
typedef struct _DOT11_WFD_DISCOVER_DEVICE_FILTER {
  DOT11_MAC_ADDRESS DeviceID;
  UCHAR             ucBitmask;
  DOT11_SSID        GroupSSID;
} DOT11_WFD_DISCOVER_DEVICE_FILTER, *PDOT11_WFD_DISCOVER_DEVICE_FILTER;
```

## Remarks

The local P2P device should not extend the discovery operation to find additional instances.

Note that if the value of **ucBitmask** is FILTER_BITMASK_DEVICE | FILTER_BITMASK_GO, the local P2P device should discover only one instance of the P2P device - either the P2P device or a GO with the desired P2P **DeviceID** and **GroupSSID**.