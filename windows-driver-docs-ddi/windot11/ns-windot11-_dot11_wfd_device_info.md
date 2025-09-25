# _DOT11_WFD_DEVICE_INFO structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

the **DOT11_WFD_DEVICE_INFO** structure is included with a [OID_DOT11_WFD_DEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-device-info) request. The structure contains Wi-Fi Direct (WFD) device information related to Peer-to-Peer (P2P) attributes.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_DEVICE_INFO** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_DEVICE_INFO_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_DEVICE_INFO_REVISION_1 |

### `DeviceAddress`

The device address to assign to a WFD port. This address is used when constructing P2P Information Elements (IEs).

### `ConfigMethods`

The configuration methods supported by the WFD device.

### `PrimaryDeviceType`

The primary device type for the WFD device.

### `DeviceName`

A friendly name assigned to the WFD device.

## Syntax

```cpp
typedef struct _DOT11_WFD_DEVICE_INFO {
  NDIS_OBJECT_HEADER    Header;
  DOT11_MAC_ADDRESS     DeviceAddress;
  USHORT                ConfigMethods;
  DOT11_WPS_DEVICE_TYPE PrimaryDeviceType;
  DOT11_WPS_DEVICE_NAME DeviceName;
} DOT11_WFD_DEVICE_INFO, *PDOT11_WFD_DEVICE_INFO;
```