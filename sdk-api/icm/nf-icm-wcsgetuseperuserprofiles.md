## Description

Determines whether the user chose to use a per-user profile association list for the specified device.

## Parameters

### `pDeviceName`

A pointer to a string containing the user-friendly name of the device.

### `dwDeviceClass`

A flag value specifying the class of the device. This parameter must take one of the following values.

| Value | Description |
|----------------|------------------------------------|
| CLASS\_MONITOR | Specifies a display device. |
| CLASS\_PRINTER | Specifies a printer. |
| CLASS\_SCANNER | Specifies an image-capture device. |

### `pUsePerUserProfiles`

A pointer to a location to receive a Boolean value that is **TRUE** if the user chose to use a per-user profile association list for the specified device; otherwise **FALSE**.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function fails if *pDeviceName* points to a device that is not of the class specified by *dwDeviceClass*.

This function is executable in Least-Privileged User Account (LUA) context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [WcsSetUsePerUserProfiles](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcssetuseperuserprofiles)