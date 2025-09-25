# NTMS_OBJECTINFORMATIONA structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_OBJECTINFORMATION** structure defines the properties that an application can get and set for RSM devices, media and system controls (such as libraries, drives, media, operator requests). This is the common structure of objects in the RSM database.

## Members

### `dwSize`

Type: **DWORD**

Size of the information structure, in bytes. This member must be set to the correct size of the structure prior to using either the
[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation) function or the
[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation) function.

### `dwType`

Type: **DWORD**

Type of device or system control for which to get/set information. This member must be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_CHANGER** | A changer object represents the robotic element of a library unit. The **Info** member is a pointer to an [NTMS_CHANGERINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_changerinformationa) structure. |
| **NTMS_CHANGER_TYPE** | A changer type object is created for each unique changer device type attached to a system. The **Info** member is a pointer to an [NTMS_CHANGERTYPEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_changertypeinformationa) structure. |
| **NTMS_COMPUTER** | The current computer object. There is no structure for the computer object. The **Info** member is a pointer to an [NTMS_COMPUTERINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_computerinformation) structure. |
| **NTMS_DRIVE** | A drive object represents a tape drive or disk drive. The **Info** member is a pointer to an [NTMS_DRIVEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_driveinformationa) structure. |
| **NTMS_DRIVE_TYPE** | A drive type object is created for each unique drive device type attached to a system. The **Info** member is a pointer to an [NTMS_DRIVETYPEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_drivetypeinformationa) structure. |
| **NTMS_IEDOOR** | An NTMS_IEDOOR object represents the door-access mechanism of a library unit. The **Info** member is a pointer to an [NTMS_IEDOORINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_iedoorinformation) structure. |
| **NTMS_IEPORT** | An NTMS_IEPORT object represents the insert/eject port of a library unit. The **Info** member is a pointer to an [NTMS_IEPORTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_ieportinformation) structure. |
| **NTMS_LIBRARY** | A library object represents an online or offline library. The **Info** member is a pointer to an [NTMS_LIBRARYINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_libraryinformation) structure. |
| **NTMS_LIBREQUEST** | A library request object is created for each request for a library to perform an action. A list of library requests is maintained by RSM as a queue of work to be performed. The **Info** member is a pointer to an [NTMS_LIBREQUESTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_librequestinformationa) structure. |
| **NTMS_LOGICAL_MEDIA** | The primary handle used by applications to access the specified medium. In the case of multi-sided media, each side is treated as an individual piece of physical media. The **Info** member is a pointer to an [NTMS_LMIDINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_lmidinformation) structure. |
| **NTMS_MEDIA_POOL** | A media pool is a logical grouping of media. All media in a media pool must be the same media type. The **Info** member is a pointer to an [NTMS_MEDIAPOOLINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_mediapoolinformation) structure. |
| **NTMS_MEDIA_TYPE** | A media type object is created for each unique media type in a system. The **Info** member is a pointer to an [NTMS_MEDIATYPEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_mediatypeinformation) structure. |
| **NTMS_OPREQUEST** | An operator request object represents an RSM request for a user to get the information. The **Info** member is a pointer to an [NTMS_OPREQUESTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_oprequestinformationa) structure. |
| **NTMS_PARTITION** | A side object represents a side of a piece of physical media. The **Info** member is a pointer to an [NTMS_PARTITIONINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_partitioninformationa) structure. |
| **NTMS_PHYSICAL_MEDIA** | A physical media object represents a magnetic tape or removable disk. A piece of physical media can contain one or more sides. The **Info** member is a pointer to an [NTMS_PMIDINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_pmidinformationa) structure. |
| **NTMS_STORAGESLOT** | A storage slot object represents one of the slots that can hold the specified medium in a library. The **Info** member is a pointer to an [NTMS_STORAGESLOTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_storageslotinformation) structure. |

### `Created`

Type: **SYSTEMTIME**

Date/time stamp when the object was created.

### `Modified`

Type: **SYSTEMTIME**

Date/time stamp when the object was modified.

### `ObjectGuid`

Type: **NTMS_GUID**

GUID of the object.

### `Enabled`

Type: **BOOL**

Indicates whether the device or system control object is enabled.

### `dwOperationalState`

Type: **DWORD**

Defines the current operational state of the object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_NOT_PRESENT** | This device or object is not currently present. |
| **NTMS_READY** | This device or object is available and ready. |
| **NTMS_NEEDS_SERVICE** | This device or object has failed and needs service. |

### `szName`

Type: **TCHAR[NTMS_OBJECTNAME_LENGTH]**

Name of the media, device, or system control object. Media pool and logical media names can be changed using the
[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation) function. All other object names are read-only.

### `szDescription`

Type: **TCHAR[NTMS_DESCRIPTION_LENGTH]**

Description of the device or system control object. The description of device and system control objects can be changed using the
[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation) function. (Writable for all objects)

### `Info.Drive.case`

### `Info.Drive.case.NTMS_DRIVE`

### `Info.DriveType.case`

### `Info.DriveType.case.NTMS_DRIVE_TYPE`

### `Info.Library.case`

### `Info.Library.case.NTMS_LIBRARY`

### `Info.Changer.case`

### `Info.Changer.case.NTMS_CHANGER`

### `Info.ChangerType.case`

### `Info.ChangerType.case.NTMS_CHANGER_TYPE`

### `Info.StorageSlot.case`

### `Info.StorageSlot.case.NTMS_STORAGESLOT`

### `Info.IEDoor.case`

### `Info.IEDoor.case.NTMS_IEDOOR`

### `Info.IEPort.case`

### `Info.IEPort.case.NTMS_IEPORT`

### `Info.PhysicalMedia.case`

### `Info.PhysicalMedia.case.NTMS_PHYSICAL_MEDIA`

### `Info.LogicalMedia.case`

### `Info.LogicalMedia.case.NTMS_LOGICAL_MEDIA`

### `Info.Partition.case`

### `Info.Partition.case.NTMS_PARTITION`

### `Info.MediaPool.case`

### `Info.MediaPool.case.NTMS_MEDIA_POOL`

### `Info.MediaType.case`

### `Info.MediaType.case.NTMS_MEDIA_TYPE`

### `Info.LibRequest.case`

### `Info.LibRequest.case.NTMS_LIBREQUEST`

### `Info.OpRequest.case`

### `Info.OpRequest.case.NTMS_OPREQUEST`

### `Info.Computer.case`

### `Info.Computer.case.NTMS_COMPUTER`

### `Info`

Device or system control object-specific information. The format of this information depends on the **dwType** member.

### `Info.Drive`

**Type: **[NTMS_DRIVEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_driveinformationa)****
This format is used if the **dwType** value is **NTMS_DRIVE**.

### `Info.DriveType`

**Type: **[NTMS_DRIVETYPEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_drivetypeinformationa)****
This format is used if the **dwType** value is **NTMS_DRIVE_TYPE**.

### `Info.Library`

**Type: **[NTMS_LIBRARYINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_libraryinformation)****
This format is used if the **dwType** value is **NTMS_LIBRARY**.

### `Info.Changer`

**Type: **[NTMS_CHANGERINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_changerinformationa)****
This format is used if the **dwType** value is **NTMS_CHANGER**.

### `Info.ChangerType`

**Type: **[NTMS_CHANGERTYPEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_changertypeinformationa)****
This format is used if the **dwType** value is **NTMS_CHANGER_TYPE**.

### `Info.StorageSlot`

**Type: **[NTMS_STORAGESLOTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_storageslotinformation)****
This format is used if the **dwType** value is **NTMS_STORAGESLOT**.

### `Info.IEDoor`

**Type: **[NTMS_IEDOORINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_iedoorinformation)****
This format is used if the **dwType** value is **NTMS_IEDOOR**.

### `Info.IEPort`

**Type: **[NTMS_IEPORTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_ieportinformation)****
This format is used if the **dwType** value is **NTMS_IEPORT**.

### `Info.PhysicalMedia`

**Type: **[NTMS_PMIDINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_pmidinformationa)****
This format is used if the **dwType** value is **NTMS_PHYSICAL_MEDIA**.

### `Info.LogicalMedia`

**Type: **[NTMS_LMIDINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_lmidinformation)****
This format is used if the **dwType** value is **NTMS_LOGICAL_MEDIA**.

### `Info.Partition`

**Type: **[NTMS_PARTITIONINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_partitioninformationa)****
This format is used if the **dwType** value is **NTMS_PARTITION**.

### `Info.MediaPool`

**Type: **[NTMS_MEDIAPOOLINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_mediapoolinformation)****
This format is used if the **dwType** value is **NTMS_MEDIA_POOL**.

### `Info.MediaType`

**Type: **[NTMS_MEDIATYPEINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_mediatypeinformation)****
This format is used if the **dwType** value is **NTMS_MEDIA_TYPE**.

### `Info.LibRequest`

**Type: **[NTMS_LIBREQUESTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_librequestinformationa)****
This format is used if the **dwType** value is **NTMS_LIBREQUEST**.

### `Info.OpRequest`

**Type: **NTMS_OPREQUESTINFORMATION****
This format is used if the **dwType** value is **NTMS_OPREQUEST**.

### `Info.Computer`

## Remarks

All members of the
**NTMS_OBJECTINFORMATION** structure are read-only at the RSM function-level unless specified as WRITABLE in the definition of the member.

> [!NOTE]
> The ntmsapi.h header defines NTMS_OBJECTINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation)

[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation)