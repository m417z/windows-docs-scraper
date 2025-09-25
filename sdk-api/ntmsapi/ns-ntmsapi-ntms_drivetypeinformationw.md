# NTMS_DRIVETYPEINFORMATIONW structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_DRIVETYPEINFORMATION** structure defines the properties specific to a type of drive supported by RSM.

## Members

### `szVendor`

Name of the vendor of the drive. This is acquired directly from the device inquiry data.

### `szProduct`

Name of the product of the drive. This is acquired directly from the device inquiry data.

### `NumberOfHeads`

This member is reserved for future use and should be ignored.

### `DeviceType`

The SCSI device type as reported from device inquiry data. From Winioctl.h. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_DEVICE_CD_ROM** | CD-ROM device. |
| **FILE_DEVICE_DISK** | Direct access device. |
| **FILE_DEVICE_DVD** | DVD device |
| **FILE_DEVICE_TAPE** | Sequential access device. |

## Remarks

The
**NTMS_DRIVETYPEINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_DRIVETYPEINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)