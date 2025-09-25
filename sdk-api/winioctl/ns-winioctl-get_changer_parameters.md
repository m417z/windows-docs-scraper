# GET_CHANGER_PARAMETERS structure

## Description

Represents the parameters of a changer.

## Members

### `Size`

The size of this structure, in bytes. The caller must set this member to `sizeof(GET_CHANGER_PARAMETERS)`.

### `NumberTransportElements`

The number of transport elements in the changer. For a SCSI changer, this is defined in the element address page. This value is almost always 1, because most changers have a single transport element with one or two picker mechanisms. A changer that has two picker mechanisms on its transport must not be represented as having two transports, because pickers are not individually addressable. High-end media libraries can have dual and multiple transport elements for fault tolerance.

### `NumberStorageElements`

The number of storage elements (slots) in the changer. For a SCSI changer, this is defined in the element address page. This value represents the maximum number of slots available for this changer including those in removable magazines, whether or not the magazines are installed. If **NumberCleanerSlots** is 1, then **NumberStorageElements** is 1 less than the maximum number of slots in the changer.

### `NumberCleanerSlots`

The number of storage elements (slots) for cleaner cartridges in the changer. If **NumberCleanerSlots** is 1, then **FirstCleanerSlotAddress** indicates the zero-based address of the slot in which a drive cleaner should be inserted. If the changer does not support drive cleaning by programmatically moving the cleaner cartridge from its slot to a drive, **NumberCleanerSlots** is 0. **NumberCleanerSlots** cannot be greater than 1.

### `NumberIEElements`

The number of import/export elements (insert/eject ports) the changer has for inserting and ejecting media. For a SCSI changer, this is defined in the element address page. An import/export element must not be part of the storage element (slot) space, and it must be possible to transport media between the import/export element and a slot using a MOVE MEDIUM command. If the changer has a door and not a true import/export element, **NumberIEElements** is 0.

### `NumberDataTransferElements`

The number of data transfer elements (drives) in the changer. For a SCSI changer, this is defined in the element address page. Unlike **NumberStorageElements**, which indicates the total number of possible slots whether or not the slots are actually present, **NumberDataTransferElements** indicates the number of drives that are actually present in the changer.

### `NumberOfDoors`

The number of doors in the changer. A door provides access to all media in the changer at once, unlike an insert/eject port, which provides access to one or more, but not all, media. A changer's door can be a physical front door or a single magazine that contains all media. If a changer supports only an insert/eject port for inserting and ejecting media, **NumberOfDoors** is 0.

### `FirstSlotNumber`

The number used by the changer vendor to identify the first storage element (slot) in the changer to the end user, either by marking a magazine or by defining a slot numbering scheme in the changer's operators guide. **FirstSlotNumber** is typically 0 or 1, but it can be the first address in a consecutive range of slot addresses defined by the vendor.

### `FirstDriveNumber`

The number used by the changer vendor to identify the first data transfer element (drive) in the changer to the end user. **FirstDriveNumber** is typically 0 or 1, but it can be the first address in a consecutive range of drive addresses defined by the vendor.

### `FirstTransportNumber`

The number used by the changer vendor to identify the first (and usually only) transport element in the changer to the end user. **FirstTransportNumber** is typically 0 or 1, but it can be the first address in a consecutive range of transport addresses defined by the vendor.

### `FirstIEPortNumber`

The number used by the changer vendor to identify the first (and usually only) insert/eject port in the changer to the end user. **FirstIEPortNumber** is typically 0 or 1, but it can be the first address in a consecutive range of insert/eject port addresses defined by the vendor. If **NumberIEElements** is 0, **FirstIEPortNumber** must also be 0.

### `FirstCleanerSlotAddress`

The number used by the changer vendor to identify the first (and only) slot address assigned to a drive cleaner cartridge to the end user. This must be the value defined by the vendor in the changer's operators guide. For example, if a changer has 8 slots numbered 1 through 8 and its operator's guide designates slot 8 as the drive cleaner slot, **FirstSlotNumber** would be 1 and **FirstCleanerSlotAddress** would be 8. If the same 8 slots were numbered 0 through 7, **FirstSlotNumber** would be 0 and **FirstCleanerSlotAddress** would be 7. If **NumberCleanerSlots** is 0, **FirstCleanerSlotAddress** must be 0.

### `MagazineSize`

The number of slots in the removable magazines in the changer. This member is valid only if CHANGER_CARTRIDGE_MAGAZINE is set in **Features0**.

### `DriveCleanTimeout`

Twice the maximum number of seconds a cleaning is expected to take. The changer's drives should be cleaned by its cleaner cartridge in half the time specified by **DriveCleanTimeout**. For example, if a drive is typically cleaned in 300 seconds (5 minutes), **DriveCleanTimeout** should be set to 600.

### `Features0`

The features supported by the changer. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CHANGER_BAR_CODE_SCANNER_INSTALLED**<br><br>0x00000001 | The changer supports a bar-code reader and the reader is installed. |
| **CHANGER_CARTRIDGE_MAGAZINE**<br><br>0x00000100 | The changer uses removable cartridge magazines for some or all storage slots. |
| **CHANGER_CLEANER_ACCESS_NOT_VALID**<br><br>0x00040000 | The ELEMENT_STATUS_ACCESS flag in a [CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element_status) structure for a data transport element is invalid when the transport element contains a cleaning cartridge. |
| **CHANGER_CLEANER_SLOT**<br><br>0x00000040 | The changer has a slot designated for a cleaner cartridge. If this flag is set, **NumberCleanerSlots** must be 1 and **FirstCleanerSlotAddress** must specify the address of the cleaner slot. |
| **CHANGER_CLOSE_IEPORT**<br><br>0x00000004 | The changer has an insert/eject port and can retract the insert/eject port programmatically. |
| **CHANGER_DEVICE_REINITIALIZE_CAPABLE**<br><br>0x08000000 | The changer can recalibrate its transport element in response to an explicit command. |
| **CHANGER_DRIVE_CLEANING_REQUIRED**<br><br>0x00010000 | The changer's drives require periodic cleaning, which must be initiated by either the user or an application, and the changer can use its transport element to mount a cleaner cartridge in a drive. |
| **CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS**<br><br>0x20000000 | The changer requires all drives to be empty (dismounted) before they can be accessed through its door. |
| **CHANGER_EXCHANGE_MEDIA**<br><br>0x00000020 | The changer can exchange media between elements. For a SCSI changer, this flag indicates whether the changer supports the EXCHANGE MEDIUM command. |
| **CHANGER_INIT_ELEM_STAT_WITH_RANGE**<br><br>0x00000002 | The changer can initialize elements within a specified range. For a SCSI changer, this flag indicates whether the changer supports the INITIALIZE ELEMENT STATUS WITH RANGE command. |
| **CHANGER_KEYPAD_ENABLE_DISABLE**<br><br>0x10000000 | The changer keypad can be enabled and disabled programmatically. |
| **CHANGER_LOCK_UNLOCK**<br><br>0x00000080 | The changer's door, insert/eject port, or keypad can be locked or unlocked programmatically. If this flag is set, **LockUnlockCapabilities** indicates which elements can be locked or unlocked. |
| **CHANGER_MEDIUM_FLIP**<br><br>0x00000200 | The changer's transport element supports flipping (rotating) media. For a SCSI changer, this flag reflects the rotate bit in the transport geometry parameters page. |
| **CHANGER_OPEN_IEPORT**<br><br>0x00000008 | The changer has an insert/eject port and can extend the insert/eject port programmatically. |
| **CHANGER_POSITION_TO_ELEMENT**<br><br>0x00000400 | The changer can position the transport to a particular destination. For a SCSI changer, this flag indicates whether the changer supports the POSITION TO ELEMENT command. If this flag is set, **PositionCapabilities** indicates the elements to which the transport can be positioned. |
| **CHANGER_PREDISMOUNT_EJECT_REQUIRED**<br><br>0x00020000 | The changer requires an explicit command issued through a mass-storage driver (tape, disk, or CDROM, for example) to eject media from a drive before the changer can move the media from a drive to a slot. |
| **CHANGER_PREMOUNT_EJECT_REQUIRED**<br><br>0x00080000 | The changer requires an explicit command issued through a mass storage driver to eject a drive mechanism before the changer can move media from a slot to the drive. For example, a changer with CD-ROM drives might require the tray to be presented to the robotic transport so that a piece of media could be loaded onto the tray during a mount operation. |
| **CHANGER_REPORT_IEPORT_STATE**<br><br>0x00000800 | The changer can report whether media is present in the insert/eject port. Such a changer must have a sensor in the insert/eject port to detect the presence or absence of media. |
| **CHANGER_SERIAL_NUMBER_VALID**<br><br>0x04000000 | The serial number is valid and unique for all changers of this type. Serial numbers are not guaranteed to be unique across vendor and product lines. |
| **CHANGER_STATUS_NON_VOLATILE**<br><br>0x00000010 | The changer uses nonvolatile memory for element status information. |
| **CHANGER_STORAGE_DRIVE**<br><br>0x00001000 | The changer can use a drive as an independent storage element; that is, it can store media in the drive without reading it. For a SCSI changer, this flag reflects the state of the DT bit in the device capabilities page. |
| **CHANGER_STORAGE_IEPORT**<br><br>0x00002000 | The changer can use an insert/eject port as an independent storage element. For a SCSI changer, this flag reflects the state of the I/E bit in the device capabilities page. |
| **CHANGER_STORAGE_SLOT**<br><br>0x00004000 | The changer can use a slot as an independent storage element for media. For a SCSI changer, this flag reflects the state of the ST bit in the device capabilities page. Slots are the normal storage location for media, so the changer must support this functionality. |
| **CHANGER_STORAGE_TRANSPORT**<br><br>0x00008000 | The changer can use a transport as an independent storage element. For a SCSI changer, this flag reflects the state of the MT bit in the device capabilities page. |
| **CHANGER_VOLUME_ASSERT**<br><br>0x00400000 | The changer can verify volume information. For a SCSI changer, this flag indicates whether the changer supports the SEND VOLUME TAG command with a send action code of ASSERT. |
| **CHANGER_VOLUME_IDENTIFICATION**<br><br>0x00100000 | The changer supports volume identification. For a SCSI changer, this flag indicates whether the changer supports the SEND VOLUME TAG and REQUEST VOLUME ELEMENT ADDRESS commands. |
| **CHANGER_VOLUME_REPLACE**<br><br>0x00800000 | The changer can replace volume information. For a SCSI changer, this flag indicates whether the changer supports the SEND VOLUME TAG command with a send action code of REPLACE. |
| **CHANGER_VOLUME_SEARCH**<br><br>0x00200000 | The changer can search for volume information. For a SCSI changer, this flag indicates whether the changer supports the supports the SEND VOLUME TAG command with a send action code of TRANSLATE. |
| **CHANGER_VOLUME_UNDEFINE**<br><br>0x01000000 | The changer can clear existing volume information. For a SCSI changer, this flag indicates whether the changer supports the SEND VOLUME TAG command with a send action code of UNDEFINE. |

### `Features1`

Any additional features supported by the changer. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CHANGER_CLEANER_AUTODISMOUNT**<br><br>0x80000004 | The changer will move the cleaning cartridge back to its original slot automatically after cleaning is finished. |
| **CHANGER_CLEANER_OPS_NOT_SUPPORTED**<br><br>0x80000040 | The changer does not support automatic cleaning of its elements. |
| **CHANGER_IEPORT_USER_CONTROL_CLOSE**<br><br>0x80000100 | The changer requires the user to manually close an open insert/eject port. |
| **CHANGER_IEPORT_USER_CONTROL_OPEN**<br><br>0x80000080 | The changer requires the user to manually open a closed insert/eject port. |
| **CHANGER_MOVE_EXTENDS_IEPORT**<br><br>0x80000200 | The changer will extend the tray automatically whenever a command is issued to move media to an insert/eject port. |
| **CHANGER_MOVE_RETRACTS_IEPORT**<br><br>0x80000400 | The changer will retract the tray automatically whenever a command is issued to move media from an insert/eject port. |
| **CHANGER_PREDISMOUNT_ALIGN_TO_DRIVE**<br><br>0x80000002 | The changer requires an explicit command to position the transport element to a drive before it can eject media from the drive. |
| **CHANGER_PREDISMOUNT_ALIGN_TO_SLOT**<br><br>0x80000001 | The changer requires an explicit command to position the transport element to a slot before it can eject media from the slot. |
| **CHANGER_RTN_MEDIA_TO_ORIGINAL_ADDR**<br><br>0x80000020 | The changer requires media to be returned to its original slot after it has been moved. |
| **CHANGER_SLOTS_USE_TRAYS**<br><br>0x80000010 | The changer uses removable trays in its slots, which require the media to be placed in a tray and the tray moved to the desired position. |
| **CHANGER_TRUE_EXCHANGE_CAPABLE**<br><br>0x80000008 | The changer can exchange media between a source and a destination in a single operation. This flag is valid only if CHANGER_EXCHANGE_MEDIA is also set in **Features0**. |

### `MoveFromTransport`

Indicates whether the changer supports moving a piece of media from a transport element to another transport element, a storage slot, an insert/eject port, or a drive. For a SCSI changer, this is defined in the device capabilities page. The transport is not typically the source or destination for moving or exchanging media.

To determine whether the changer can move media to a given element, use the following values.

| Value | Meaning |
| --- | --- |
| **CHANGER_TO_DRIVE**<br><br>0x08 | The changer can carry out the operation from the specified element to a drive. |
| **CHANGER_TO_IEPORT**<br><br>0x04 | The changer can carry out the operation from the specified element to an insert/eject port. |
| **CHANGER_TO_SLOT**<br><br>0x02 | The changer can carry out the operation from the specified element to a storage slot. |
| **CHANGER_TO_TRANSPORT**<br><br>0x01 | The changer can carry out the operation from the specified element to a transport. |

### `MoveFromSlot`

Indicates whether the changer supports moving medium from a storage slot to a transport element, another storage slot, an insert/eject port, or a drive. Use the flags described under **MoveFromTransport** to determine whether the changer supports the move.

### `MoveFromIePort`

Indicates whether the changer supports moving medium from an insert/eject port to a transport element, a storage slot, another insert/eject port, or a drive. For a SCSI changer, this is defined in the device capabilities page. Use the flags described under **MoveFromTransport** to determine whether the changer supports the move.

### `MoveFromDrive`

Indicates whether the changer supports moving medium from a drive to a transport element, a storage slot, an insert/eject port, or another drive. Use the flags described under **MoveFromTransport** to determine whether the changer supports the move.

### `ExchangeFromTransport`

Indicates whether the changer supports exchanging medium between a transport element and another transport element, a storage slot, an insert/eject port, or a drive. Use the flags described under **MoveFromTransport** to determine whether the changer supports the exchange.

### `ExchangeFromSlot`

Indicates whether the changer supports exchanging medium between a storage slot and a transport element, another storage slot, an insert/eject port, or a drive. Use the flags described under **MoveFromTransport** to determine whether the changer supports the exchange.

### `ExchangeFromIePort`

Indicates whether the changer supports exchanging medium between an insert/eject port and a transport element, a storage slot, another insert/eject port, or a drive. Use the flags described under **MoveFromTransport** to determine whether the changer supports the exchange.

### `ExchangeFromDrive`

Indicates whether the changer supports exchanging medium between a drive and a transport element, a storage slot, an insert/eject port, or another drive. Use the flags described under **MoveFromTransport** to determine whether the changer supports the exchange.

### `LockUnlockCapabilities`

The elements of a changer that can be locked or unlocked programmatically. This member is valid only if CHANGER_LOCK_UNLOCK is set in **Features0**.

To determine whether the changer can lock or unlock a particular element, use one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LOCK_UNLOCK_DOOR**<br><br>0x02 | The changer can lock or unlock its door. |
| **LOCK_UNLOCK_IEPORT**<br><br>0x01 | The changer can lock or unlock its insert/eject port. |
| **LOCK_UNLOCK_KEYPAD**<br><br>0x04 | The changer can lock or unlock its keypad. |

### `PositionCapabilities`

The elements to which a changer can position its transport. Use the flags described under **MoveFromTransport** to determine whether the changer supports positioning the transport to a particular element. This member is valid only if CHANGER_POSITION_TO_ELEMENT is set in **Features0**.

### `Reserved1`

Reserved for future use.

### `Reserved2`

Reserved for future use.

## See also

[IOCTL_CHANGER_GET_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_get_parameters)