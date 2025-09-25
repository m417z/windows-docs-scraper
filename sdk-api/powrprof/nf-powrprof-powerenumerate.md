# PowerEnumerate function

## Description

Enumerates the specified elements in a power scheme. This function is normally called in a
loop incrementing the *Index* parameter to retrieve subkeys until they've all been
enumerated.

## Parameters

### `RootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `SchemeGuid` [in, optional]

The identifier of the power scheme. If this parameter is **NULL**,
an enumeration of the power policies is returned.

### `SubGroupOfPowerSettingsGuid` [in, optional]

The subgroup of power settings. If this parameter is **NULL**, an
enumeration of settings under the **PolicyGuid** key is returned.

| Value | Meaning |
| --- | --- |
| **NO_SUBGROUP_GUID**<br><br>fea3413e-7e05-4911-9a71-700331f1c294 | Settings in this subgroup will be part of the default power scheme. |
| **GUID_DISK_SUBGROUP**<br><br>0012ee47-9041-4b5d-9b77-535fba8b1442 | Settings in this subgroup control power management configuration of the system's hard disk drives. |
| **GUID_SYSTEM_BUTTON_SUBGROUP**<br><br>4f971e89-eebd-4455-a8de-9e59040e7347 | Settings in this subgroup control configuration of the system power buttons. |
| **GUID_PROCESSOR_SETTINGS_SUBGROUP**<br><br>54533251-82be-4824-96c1-47b60b740d00 | Settings in this subgroup control configuration of processor power management features. |
| **GUID_VIDEO_SUBGROUP**<br><br>7516b95f-f776-4464-8c53-06167f40cc99 | Settings in this subgroup control configuration of the video power management features. |
| **GUID_BATTERY_SUBGROUP**<br><br>e73a048d-bf27-4f12-9731-8b2076e8891f | Settings in this subgroup control battery alarm trip points and actions. |
| **GUID_SLEEP_SUBGROUP**<br><br>238C9FA8-0AAD-41ED-83F4-97BE242C8F20 | Settings in this subgroup control system sleep settings. |
| **GUID_PCIEXPRESS_SETTINGS_SUBGROUP**<br><br>501a4d13-42af-4429-9fd1-a8218c268e20 | Settings in this subgroup control PCI Express settings. |

### `AccessFlags` [in]

A set of flags that specifies what will be enumerated

| Value | Meaning |
| --- | --- |
| **ACCESS_SCHEME**<br><br>16 | Enumerate power schemes. The *SchemeGuid* and *SubgroupOfPowerSettingsGuid* parameters will be ignored. |
| **ACCESS_SUBGROUP**<br><br>17 | Enumerate subgroups under *SchemeGuid*. The *SubgroupOfPowerSettingsGuid* parameter will be ignored. |
| **ACCESS_INDIVIDUAL_SETTING**<br><br>18 | Enumerate individual power settings under *SchemeGuid*\*SubgroupOfPowerSettingsGuid*. To enumerate power settings directly under the *SchemeGuid* key, use **NO_SUBGROUP_GUID** as the *SubgroupOfPowerSettingsGuid* parameter. |

### `Index` [in]

The zero-based index of the scheme, subgroup, or setting that is being enumerated.

### `Buffer` [out, optional]

A pointer to a variable to receive the elements. If this parameter is **NULL**, the function retrieves the size of the buffer required.

### `BufferSize` [in, out]

A pointer to a variable that on input contains the size of the buffer pointed to by
the *Buffer* parameter. If the *Buffer* parameter is
**NULL** or if the *BufferSize* is not large enough, the function
will return **ERROR_MORE_DATA** and the variable receives the required buffer size.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed. If the buffer size passed in the *BufferSize* parameter is too small,
or if the *Buffer* parameter is **NULL**,
**ERROR_MORE_DATA** will be returned and the **DWORD** pointed to
by the *BufferSize* parameter will be filled in with the required buffer size.

## See also

[POWER_DATA_ACCESSOR](https://learn.microsoft.com/windows/desktop/api/powrprof/ne-powrprof-power_data_accessor)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)