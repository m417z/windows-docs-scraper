# _DOT11_POWER_MGMT_MODE_STATUS_INFO structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_POWER_MGMT_MODE_STATUS_INFO structure describes the power mode of the hardware.

## Members

### `Header`

The type, revision, and size of the DOT11_POWER_MGMT_MODE_STATUS_INFO structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_POWER_MGMT_MODE_STATUS_INFO_REVISION_1 |
| **Size** | DOT11_SIZEOF_POWER_MGMT_MODE_STATUS_INFO_REVISION_1 |

### `PowerSaveMode`

The current power mode of the hardware. The mode may be **dot11_power_mode_active** or **dot11_power_mode_powersave**, but should not be **dot11_power_mode_unknown**.

### `uPowerSaveLevel`

One of the following values describing power saving levels:

| Value | Meaning |
| --- | --- |
| DOT11_POWER_SAVING_NO_POWER_SAVING | No power saving |
| DOT11_POWER_SAVING_FAST_PSP | Fast PSP |
| DOT11_POWER_SAVING_MAX_PSP | Maximum PSP |
| DOT11_POWER_SAVING_MAXIMUM_LEVEL | Maximum power saving level |

### `Reason`

Reason that the device changed into the current power mode.

## Syntax

```cpp
typedef struct _DOT11_POWER_MGMT_MODE_STATUS_INFO {
  NDIS_OBJECT_HEADER      Header;
  DOT11_POWER_MODE        PowerSaveMode;
  ULONG                   uPowerSaveLevel;
  DOT11_POWER_MODE_REASON Reason;
} DOT11_POWER_MGMT_MODE_STATUS_INFO, *PDOT11_POWER_MGMT_MODE_STATUS_INFO;
```

## Remarks

At each transition of the mode change, a device should remember the reason it made the last change.