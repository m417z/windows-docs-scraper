# PowerWriteACValueIndex function

## Description

Sets the AC value index of the specified power setting.

## Parameters

### `RootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `SchemeGuid` [in]

The identifier of the power scheme.

### `SubGroupOfPowerSettingsGuid` [in, optional]

The subgroup of power settings. This parameter can be one of the following values defined in WinNT.h. Use **NO_SUBGROUP_GUID** to refer to the
default power scheme.

| Value | Meaning |
| --- | --- |
| **NO_SUBGROUP_GUID**<br><br>fea3413e-7e05-4911-9a71-700331f1c294 | Settings in this subgroup are part of the default power scheme. |
| **GUID_DISK_SUBGROUP**<br><br>0012ee47-9041-4b5d-9b77-535fba8b1442 | Settings in this subgroup control power management configuration of the system's hard disk drives. |
| **GUID_SYSTEM_BUTTON_SUBGROUP**<br><br>4f971e89-eebd-4455-a8de-9e59040e7347 | Settings in this subgroup control configuration of the system power buttons. |
| **GUID_PROCESSOR_SETTINGS_SUBGROUP**<br><br>54533251-82be-4824-96c1-47b60b740d00 | Settings in this subgroup control configuration of processor power management features. |
| **GUID_VIDEO_SUBGROUP**<br><br>7516b95f-f776-4464-8c53-06167f40cc99 | Settings in this subgroup control configuration of the video power management features. |
| **GUID_BATTERY_SUBGROUP**<br><br>e73a048d-bf27-4f12-9731-8b2076e8891f | Settings in this subgroup control battery alarm trip points and actions. |
| **GUID_SLEEP_SUBGROUP**<br><br>238C9FA8-0AAD-41ED-83F4-97BE242C8F20 | Settings in this subgroup control system sleep settings. |
| **GUID_PCIEXPRESS_SETTINGS_SUBGROUP**<br><br>501a4d13-42af-4429-9fd1-a8218c268e20 | Settings in this subgroup control PCI Express settings. |

### `PowerSettingGuid` [in, optional]

The identifier of the power setting.

### `AcValueIndex` [in]

The AC value index.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## Remarks

Changes to the settings for the active power scheme do not take effect until you call the
[PowerSetActiveScheme](https://learn.microsoft.com/windows/desktop/api/powersetting/nf-powersetting-powersetactivescheme) function.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)