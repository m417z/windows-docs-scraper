# NTMS_CHANGERTYPEINFORMATIONW structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_CHANGERTYPEINFORMATION** structure defines the properties specific to a type of robotic changer supported by RSM.

## Members

### `szVendor`

Name of the vendor of the changer. This is acquired directly from the device inquiry data.

### `szProduct`

Product name of the changer. This is acquired directly from the device inquiry data.

### `DeviceType`

SCSI device type as reported from device inquiry data. From Winioctl.h. This can be the following value.

| Value | Meaning |
| --- | --- |
| **FILE_DEVICE_CHANGER** | Changer device. |

## Remarks

The
**NTMS_CHANGERTYPEINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_CHANGERTYPEINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)