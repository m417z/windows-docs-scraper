# _DOT11_VWIFI_COMBINATION_V3 structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_VWIFI_COMBINATION_V3** structure contains the combination of MAC entities that an 802.11 wireless miniport driver simultaneously supports when virtualized.

## Members

### `Header`

The type, revision, and size of the **DOT11_VWIFI_COMBINATION_V3** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_VWIFI_COMBINATION_REVISION_3 |
| **Size** | DOT11_SIZEOF_VWIFI_COMBINATION_REVISION_3 |

### `uNumInfrastructure`

The number of 802.11 infrastructure stations supported.

### `uNumAdhoc`

The number of adhoc stations supported.

### `uNumSoftAP`

The number of soft access point stations supported.

### `uNumVirtualStation`

The number of virtual stations supported.

### `uNumWFDGroup`

The number of simultaneous operational Wi-Fi Direct (WFD) groups supported.

## Syntax

```cpp
typedef struct _DOT11_VWIFI_COMBINATION_V3 {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumInfrastructure;
  ULONG              uNumAdhoc;
  ULONG              uNumSoftAP;
  ULONG              uNumVirtualStation;
  ULONG              uNumWFDGroup;
} DOT11_VWIFI_COMBINATION_V3, *PDOT11_VWIFI_COMBINATION_V3;
```

## Remarks

When **uNumWFDGroup** > 0, the miniport driver is required to support one more 802.11 MAC entity in addition to the number in **uNumWFDGroup**. This additional entity is used for WFD device functionality and is the only entity configured as **DOT11_OPERATION_MODE_WFD_DEVICE**.