# NTMS_CHANGERINFORMATIONW structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_CHANGERINFORMATION** structure defines properties specific to a robotic changer object.

## Members

### `Number`

Number of the changer within the library.

### `ChangerType`

Identifier of the changer type of this changer.

### `szSerialNumber`

Serial number for the changer represented as a string. Devices that do not support serial numbers report **NULL** for this member.

### `szRevision`

Revision for the changer, represented as a string.

### `szDeviceName`

Name of the device used to access the changer.

### `ScsiPort`

SCSI host adapter to which the changer is connected.

### `ScsiBus`

SCSI bus to which the changer is connected.

### `ScsiTarget`

SCSI target ID for the changer.

### `ScsiLun`

SCSI logical unit ID for the changer.

### `Library`

Unique identifier of the library that contains the changer.

## Remarks

The
**NTMS_CHANGERINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_CHANGERINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)