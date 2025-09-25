## Description

Enables a user to specify whether or not to use a per-user profile association list for the specified device.

## Parameters

### `pDeviceName`

A pointer to a string that contains the user-friendly name of the device.

### `dwDeviceClass`

A flag value that specifies the class of the device. This parameter must take one of the following values:

| Value | Description |
|----------------|------------------------------------|
| CLASS\_MONITOR | Specifies a display device. |
| CLASS\_PRINTER | Specifies a printer. |
| CLASS\_SCANNER | Specifies an image capture device. |

### `usePerUserProfiles`

A Boolean value that is **TRUE** if the user wants to use a per-user profile association list for the specified device; otherwise **FALSE**.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If *usePerUserProfiles* is **TRUE**, and the user is not already using a per-user profile association list for *pDeviceName*, then the per-user profile association list is initialized by making a copy of the system-wide profile association list for the same device. From then on, changes to the system-wide list are not included in the per-user list.

This function is executable in Least-Privileged User Account (LUA) context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [WcsGetUsePerUserProfiles](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsgetdefaultrenderingintent)