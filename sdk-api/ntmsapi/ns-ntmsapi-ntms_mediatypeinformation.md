# NTMS_MEDIATYPEINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_MEDIATYPEINFORMATION** structure defines the properties specific to a type of media supported by RSM.

## Members

### `MediaType`

Each disk or tape driver reports the media-type enumeration value of the medium that is currently mounted in the drive. This member can be one of the values in the
[STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type) enumeration type. This unique media type value is mapped to a human-readable string in the object **szName** member.

### `NumberOfSides`

Number of sides on the media.

### `ReadWriteCharacteristics`

Identifies the read/write characteristics of the media type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_MEDIARW_REWRITABLE** | Media that can be rewritten. This includes magnetic tape, magnetic disk, and some optical disk media. |
| **NTMS_MEDIARW_WRITEONCE** | Media that can only be written to one time. Some optical media, for example, 5.25", 12", 14" WORM, and CD-R, are designed to be write-once. |
| **NTMS_MEDIARW_READONLY** | Media that cannot be written to CD-ROM and DVD-ROM. |

### `DeviceType`

SCSI device type as reported from device inquiry data. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_DEVICE_CD_ROM** | CD-ROM device. |
| **FILE_DEVICE_DISK** | Direct access device. |
| **FILE_DEVICE_TAPE** | Sequential access device. |

## Remarks

The
**NTMS_MEDIATYPEINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)