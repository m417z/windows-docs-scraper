# PowerReadDescription function

## Description

Retrieves the description for the specified power setting, subgroup, or scheme. If the
*SchemeGuid* parameter is not **NULL** but both the
*SubGroupOfPowerSettingsGuid* and *PowerSettingGuid* parameters
are **NULL**, the description of the power scheme will be returned. If the
*SchemeGuid* and *SubGroupOfPowerSettingsGuid* parameters are not
**NULL** and the *PowerSettingGuid* parameter is
**NULL**, the description of the subgroup will be returned. If the
*SchemeGuid*, *SubGroupOfPowerSettingsGuid*, and
*PowerSettingGuid* parameters are not **NULL**, the description of
the power setting will be returned.

## Parameters

### `RootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `SchemeGuid` [in, optional]

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

The identifier of the power setting that is being used.

### `Buffer` [out, optional]

A pointer to a buffer that receives the description. If this parameter is **NULL**,
the *BufferSize*
parameter receives the required buffer size. The strings returned are all wide (Unicode) strings.

### `BufferSize` [in, out]

A pointer to a variable that contains the size of the buffer pointed to by the
*Buffer* parameter.

If the *Buffer* parameter is **NULL**, the function returns ERROR_SUCCESS and the variable receives the required buffer size.

If the specified buffer size is not large enough to hold the
requested data, the function returns **ERROR_MORE_DATA** and the variable receives the required buffer size.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed. If the buffer size specified by the *BufferSize* parameter is too small,
the function returns
**ERROR_SUCCESS** and the **DWORD** pointed
to by the *BufferSize* parameter is filled in with the required buffer size.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)