# BCLASS_DISABLE_STATUS_NOTIFY_CALLBACK callback function

## Description

*BatteryMiniDisableStatusNotify* disables status notification for a battery device.

This callback function is specified in the [BATTERY_MINIPORT_INFO_V1_1](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_info_v1_1) structure.

## Parameters

### `Context` [in]

A pointer to the context area allocated by the miniclass driver for the battery device.

## Return value

*BatteryMiniDisableStatusNotify* returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A battery is currently installed and status notification has been disabled. |
| **STATUS_NO_SUCH_DEVICE** | No battery is present. |
| **STATUS_NOT_SUPPORTED** | No functionality is provided for this routine. |

## Remarks

The battery class driver calls *BatteryMiniDisableStatusNotify* when it no longer requires notification of battery conditions set in an earlier call to *BatteryMiniSetStatusNotify*.

Miniclass drivers that supply a fully functional *BatteryMiniDisableStatusNotify* routine must also supply a fully functional *BatteryMiniSetStatusNotify* routine, and vice versa.

## See also

[BatteryClassStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassstatusnotify)

[BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback)