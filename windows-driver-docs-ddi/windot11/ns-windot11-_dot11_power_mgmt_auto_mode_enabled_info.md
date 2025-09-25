# _DOT11_POWER_MGMT_AUTO_MODE_ENABLED_INFO structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_POWER_MGMT_AUTO_MODE_ENABLED structure describes to a device whether to automatically manage its power saving mode.

## Members

### `Header`

The type, revision, and size of the DOT11_POWER_MGMT_AUTO_MODE_ENABLED_INFO structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_POWER_MGMT_AUTO_MODE_ENABLED_REVISION_1 |
| **Size** | DOT11_SIZEOF_POWER_MGMT_AUTO_MODE_ENABLE_INFO_REVISION_1 |

### `bEnabled`

Windows sets this member to TRUE to indicate to the device to automatically manage its power saving mode. Windows set this to FALSE to indicate to the device to stop automatically managing its power save mode.

## Syntax

```cpp
typedef struct _DOT11_POWER_MGMT_AUTO_MODE_ENABLED_INFO {
  NDIS_OBJECT_HEADER Header;
  BOOLEAN            bEnabled;
} DOT11_POWER_MGMT_AUTO_MODE_ENABLED_INFO, *PDOT11_POWER_MGMT_AUTO_MODE_ENABLED_INFO;
```

## Remarks

When Windows sets the device to auto power saving mode, devices must remain in this mode until Windows issues another request with **bEnabled** set to FALSE. In auto power saving mode, Windows may issue a [OID_DOT11_POWER_MGMT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-power-mgmt-request)*set* request that hardware can use as a hint to adjust its power management.