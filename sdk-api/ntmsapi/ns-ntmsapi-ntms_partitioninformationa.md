# NTMS_PARTITIONINFORMATIONA structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_PARTITIONINFORMATION** structure defines the properties specific to the side object.

## Members

### `PhysicalMedia`

Unique physical media identifier for the medium that contains this side.

### `LogicalMedia`

Unique logical media identifier (LMID) for a piece of logical media that contains this side. This parameter is a **NULL** if the side is not allocated.

### `State`

Side life cycle information. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_PARTSTATE_ALLOCATED** | The media has been allocated to an application. |
| **NTMS_PARTSTATE_AVAILABLE** | The media is available to be allocated. |
| **NTMS_PARTSTATE_COMPLETE** | The media has been completely written and marked as complete by an application. |
| **NTMS_PARTSTATE_DECOMMISIONED** | The media is unsuitable for data storage and is no longer usable. |
| **NTMS_PARTSTATE_INCOMPATIBLE** | The media has been found to be and marked as incompatible with the drive. |
| **NTMS_PARTSTATE_FOREIGN** | The media is in a unrecognized pool. |
| **NTMS_PARTSTATE_IMPORT** | The media is in the import pool. |
| **NTMS_PARTSTATE_UNPREPARED** | The media is waiting for a free label to be applied. |
| **NTMS_PARTSTATE_RESERVED** | The side has been reserved by the [AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media) function with the *dwOption* parameter set to NTMS_ALLOCATE_NEW. |

### `Side`

Zero-relative value which indicates which side of a multi-sided media this is. For single-sided media, such as tape, this value is always zero. For dual-sided media one NTMS_PARITIONINFORMATION record has this property set to zero - the "A" side - and a second NTMS_PARTITIONINFORMATION record has it set to 1 - the "B" side.

### `dwOmidLabelIdLength`

Length of the label ID string of the on-media identifier.

### `OmidLabelId`

Label ID unique identifier of the on-media identifier.

### `szOmidLabelType`

Label type of the on-media identifier.

### `szOmidLabelInfo`

Label information of the on-media identifier.

### `dwMountCount`

Number of times this media has been mounted into a drive. This is initialized to zero when the objects are created in the database.

### `dwAllocateCount`

Number of times this media has been allocated.

### `Capacity`

Number bytes of storage available on this side.

## Remarks

The
**NTMS_PARTITIONINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_PARTITIONINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)