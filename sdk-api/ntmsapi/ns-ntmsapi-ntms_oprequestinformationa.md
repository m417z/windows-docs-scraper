# NTMS_OPREQUESTINFORMATIONA structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_OPREQUESTINFORMATION** structure defines the properties specific to operator-request system control for RSM.

## Members

### `Request`

Type of operator request. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_OPREQ_NEWMEDIA** | An application attempting to allocate media sends an operator request for new media when no media is available. When this flag is set, the **Arg1** member should be set to the GUID of the media pool requiring new media. Optionally, the **Arg2** member can be set to the particular library in which the new media should be placed. |
| **NTMS_OPREQ_CLEANER** | RSM sends an operator request for a cleaner when a clean operation is queued and no cleaner is online and available to the drive. When this flag is set, the **Arg1** member should be set to the GUID of the library requiring the cleaning cartridge. |
| **NTMS_OPREQ_DEVICESERVICE** | An application or RSM sends an operator request for drive service when a changer device or drive is experiencing problems. When this flag is set, the **Arg1** member should be set to the GUID of the device requiring service. |
| **NTMS_OPREQ_MOVEMEDIA** | An application or RSM sends an operator request to move the specified medium to service a mount for offline media or to eject media to an offline library. When this flag is set, the **Arg1** member should be set to the GUID of the physical media to move and the **Arg2** member should be set to the GUID of the library this media should be moved to. |
| **NTMS_OPREQ_MESSAGE** | An application-specific operator request. Text only. |

### `Submitted`

System time when the operator request was submitted.

### `State`

Current state of the operator service request. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_OPSTATE_SUBMITTED** | The operator request has been submitted but not read by an operator console. |
| **NTMS_OPSTATE_ACTIVE** | The operator request has been read by one or more operator consoles and might be in process. |
| **NTMS_OPSTATE_INPROGRESS** | The user has acknowledged this operator request and is in the process of performing the service. |
| **NTMS_OPSTATE_REFUSED** | The user has rejected the operator service request. |
| **NTMS_OPSTATE_COMPLETE** | The user has completed the operator service request. |

### `szMessage`

Operator message text.

### `Arg1Type`

Type of the **Arg1** object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_UNKNOWN** | No object provided in **Arg1Type**. |
| **NTMS_CHANGER** | Medium changer object. |
| **NTMS_DRIVE** | Drive object. |
| **NTMS_IEDOOR** | Library door object. |
| **NTMS_IEPORT.** | Library insert/eject port object |
| **NTMS_LIBRARY** | Library object. |
| **NTMS_PARTITION** | Side object. |
| **NTMS_PHYSICAL_MEDIA** | Physical media object. |
| **NTMS_STORAGESLOT** | Library slot object. |

### `Arg1`

**Arg1** object ID used for move requests or other operator requests that require a reference object. The purpose of this object varies based on the type of operator request. For appropriate uses of **Arg1**, see the **Request** description.

### `Arg2Type`

Type of **Arg2** object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_UNKNOWN** | No object provided in **Arg2Type**. |
| **NTMS_LIBRARY** | Library object. |

### `Arg2`

**Arg2** object ID used for operator requests that require a second reference object. The purpose of this object varies based on the type of operator request. For appropriate uses of **Arg2**, see the **Request** description.

### `szApplication`

Application that submitted the operator request.

### `szUser`

Interactive user logged on to the computer that submitted the operator request.

### `szComputer`

Computer that submitted the operator request.

## Remarks

The
**NTMS_OPREQUESTINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_OPREQUESTINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)