## Description

Contains information that defines a color profile. See [Using device profiles with WCS](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs) for more information.

## Members

### `dwType`

Must be set to one of the following values.

| Value | Meaning |
|--------------------|----------------------------------------------------------------------------------------------------------------------------|
| PROFILE\_FILENAME | Indicates that the **pProfileData** member contains a null-terminated string that holds the name of a device profile file. |
| PROFILE\_MEMBUFFER | Indicates that the **pProfileData** member contains a pointer to a device profile in a memory buffer. |

### `pProfileData`

The contents of this member is indicated by the **dwTYPE** member. It will either be a pointer to a null-terminated string containing the file name of the device profile, or it will be a pointer to a buffer in memory containing the device profile data.

### `cbDataSize`

The size in bytes of the data buffer pointed to by the **pProfileData** member.

## Remarks

## See also

* [Using device profiles with WCS](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs)