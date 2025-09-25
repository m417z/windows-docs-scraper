# _DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

the **DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST** structure is included with a [OID_DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-secondary-device-type-list) request. The structure contains the list of secondary device types advertised by a Wi-Fi Direct device.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_SECONDARY_DEVICE_TYPE_LIST_REVISION_1 |

### `uNumOfEntries`

The number of entries present in **SecondaryDeviceTypes**.

### `uTotalNumOfEntries`

The maximum number of entries the **SecondaryDeviceTypes** array can contain.

### `SecondaryDeviceTypes`

An array of secondary device types.

## Syntax

```cpp
typedef struct _DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST {
  NDIS_OBJECT_HEADER    Header;
  ULONG                 uNumOfEntries;
  ULONG                 uTotalNumOfEntries;
  DOT11_WFD_DEVICE_TYPE SecondaryDeviceTypes[1];
}  DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST, *PDOT11_WFD_SECONDARY_DEVICE_TYPE_LIST;
```