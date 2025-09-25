# NTMS_LIBRARYINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_LIBRARYINFORMATION** structure defines properties specific to a library object.

## Members

### `LibraryType`

Library type object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_LIBRARYTYPE_ONLINE** | A robotic element that automates the mounting and dismounting of media into one or more drives. |
| **NTMS_LIBRARYTYPE_STANDALONE** | A stand-alone drive that is modeled as a library with one drive in RSM. |
| **NTMS_LIBRARYTYPE_OFFLINE** | Media that is not in a library is in the offline library. |
| **NTMS_LIBRARYTYPE_UNKNOWN** | Library type cannot be determined. |

### `CleanerSlot`

For each library, this represents the slot that was assigned to the cleaner cartridge. If this member is **NULL**, there is no cleaner slot defined for this library.

### `CleanerSlotDefault`

Represents a libraries' default or preferred cleaner slot. If **NULL**, there is not a preferred slot.

### `LibrarySupportsDriveCleaning`

Used by drives that require cleaning under robotics control. If **TRUE**, automatic drive cleaning operations are enabled.

### `BarCodeReaderInstalled`

Returns **TRUE** if a bar code reader is installed in a library; otherwise returns **FALSE**.

### `InventoryMethod`

Default or user-selected method for performing inventory of this library. (This member is writable.) This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_INVENTORY_FAST** | If the library has a bar-code reader installed, this value causes a bar-code inventory to be performed. If the library does not have a bar-code reader, this flag causes a differential inventory to be performed (slots which transitioned from empty to full are classified). |
| **NTMS_INVENTORY_OMID** | A full inventory involves mounting each side in a library and reading the on-media identification from the media. This type of inventory can be very time consuming for some library units. |
| **NTMS_INVENTORY_NONE** | After the library door is closed, no inventory is performed. Inventory might be required if a mount label-check fails. |

### `dwCleanerUsesRemaining`

Number of uses remaining on the cleaner in the library. This member is zero if no cleaner is present or if the library does not support cleaning.

### `FirstDriveNumber`

Number of the first drive in the library.

### `dwNumberOfDrives`

Number of drives in the library.

### `FirstSlotNumber`

Number of the first slot in the library.

### `dwNumberOfSlots`

Number of slots in the library.

### `FirstDoorNumber`

Number of the first access door in the library.

### `dwNumberOfDoors`

Number of access doors in the library.

### `FirstPortNumber`

Number of the first insert/eject port in the library.

### `dwNumberOfPorts`

Number of insert/eject ports in the library.

### `FirstChangerNumber`

Number of the first changer in the library.

### `dwNumberOfChangers`

Number of changers in the library.

### `dwNumberOfMedia`

Number of media in the online or offline library.

### `dwNumberOfMediaTypes`

Number of media types supported by the library.

### `dwNumberOfLibRequests`

Number of current library requests.

### `Reserved`

Reserved.

### `AutoRecovery`

If this member is **TRUE**, a full inventory will be performed if a mount fails. The failure may be either hardware or label mismatch. For ATAPI CD libraries, this parameter cannot be disabled. The default is **TRUE**. Large library owners should disable this feature.

### `dwFlags`

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_LIBRARYFLAG_FIXEDOFFLINE** | The library is an offline library, not a library that is not present. |
| **NTMS_LIBRARYFLAG_CLEANERPRESENT** | A cleaner is present in the changer. |
| **NTMS_LIBRARYFLAG_IGNORECLEANERUSESREMAINING** | The cleaner cartridge will be used until it no longer cleans the drive, instead of keeping track of the number of cleanings left. Do not set this flag directly. It is set or cleared based on the value of **dwCleanerUsesRemaining**. It is set if **dwCleanerUsesRemaining** is 0xFFFFFFFF, and cleared otherwise. |
| **NTMS_LIBRARYFLAG_RECOGNIZECLEANERBARCODE** | Treat barcoded cartridges that have CLN as a prefix as cleaner cartridges, instead of mounting them in the drive to identify them. |

## Remarks

For offline libraries, only **LibraryType** and **dwNumberOfMedia** are reported. All other values should be ignored.

The
**NTMS_LIBRARYINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)