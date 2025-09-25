# NTMS_PMIDINFORMATIONA structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_PMIDINFORMATION** structure defines the properties specific to a physical media object.

## Members

### `CurrentLibrary`

Unique ID of the library in which the media is contained.

### `MediaPool`

Unique ID of the media pool to which the media is assigned.

### `Location`

Unique ID of the physical location object for the media.

### `LocationType`

Current location type of a piece of physical media. The value of this member can be set to NTMS_STORAGESLOT, NTMS_DRIVE, NTMS_IEPORT. (Offline media are in slots.)

### `MediaType`

Unique ID of a media type object.

### `HomeSlot`

Unique ID of the library storage slot in which media is stored.

### `szBarCode`

String that matches the bar-code value on a bar-code label of a piece of physical media.

### `BarCodeState`

Current state of the bar code. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_BARCODESTATE_OK** | The media has a bar code and it is readable. |
| **NTMS_BARCODESTATE_UNREADABLE** | The media either does not have a bar code or the bar code is unreadable. |

### `szSequenceNumber`

Sequential number assigned to the specified medium as a human-readable value that must be transcribed by a user on the medium so that the medium can be located in an offline library.

### `MediaState`

Current state for the piece of physical media. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_MEDIASTATE_IDLE** | The media is in a slot in the library, in a drive dismounted, or in an offline library. |
| **NTMS_MEDIASTATE_INUSE** | The media is marked as in use as soon as a request for an operation is successfully made to RSM. |
| **NTMS_MEDIASTATE_LOADED** | The state of the media when RSM has determined that the media is available for reading and writing. |
| **NTMS_MEDIASTATE_MOUNTED** | The state of a piece of physical media when the media is placed in a drive. |
| **NTMS_MEDIASTATE_OP_ERROR** | The physical media is in an error state that is recoverable. No operator intervention is required. |
| **NTMS_MEDIASTATE_UNLOADED** | The state of the media when it is ready to be removed from a drive. The drive state, DISMOUNTABLE, also indicates that a drive can be removed at any time. |
| **NTMS_MEDIASTATE_OPREQ** | Media is waiting for operator request. |

### `dwNumberOfPartitions`

Number of sides on the medium.

### `dwMediaTypeCode`

SCSI media type code.

### `dwDensityCode`

SCSI density code.

### `MountedPartition`

Globally unique ID of the side of the media that is currently mounted.

## Remarks

The
**NTMS_PMIDINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_PMIDINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)