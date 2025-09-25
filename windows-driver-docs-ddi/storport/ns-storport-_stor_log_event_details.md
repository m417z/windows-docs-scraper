# _STOR_LOG_EVENT_DETAILS structure

## Description

The **STOR_LOG_EVENT_DETAILS** structure provides details pertaining to Storport-specific error log events and system log events.

## Members

### `InterfaceRevision`

The revision number of this interface. Set to STOR_CURRENT_LOG_INTERFACE_REVISION to use the version of the interface that matches this structure. Both the constant and the data structure are defined in the same header file. This member is set to 0x00000100 for the first revision.

### `Size`

The size of this structure. Set before calling [StorPortLogSystemEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogsystemevent).

### `Flags`

Not currently used. Must be zero.

### `EventAssociation`

Specifies whether the event should be associated with the adapter, the target, or the LUN. For adapter- and target-associated events, the event is logged against the adapter's device object. For LUN-associated events, the event is logged against the LUN's device object if it exists; otherwise, it is logged against the adapter's device object.

### `PathId`

The SCSI path/bus corresponding to this event.

### `TargetId`

The SCSI target controller or device on the bus corresponding to this event.

### `LunId`

The SCSI logical unit number of the target device corresponding to this event.

### `StorportSpecificErrorCode`

If the **ErrorCode** value is specific to Storport and should be translated for use with IOLOGMSG.DLL, this value is set to **TRUE**. If the **ErrorCode** value is not specific to Storport and should be passed directly to the system event logging facility, this value is set to **FALSE**.

### `ErrorCode`

The event error code to log.

### `UniqueId`

Specifies a unique identifier associated with the ErrorCode. Often this is used as a location code, referencing the location in the miniport that triggered the event. This value is passed directly to the event logging facility.

### `DumpDataSize`

The size of the miniport-specific data block that is to be appended to the log entry. If no data block is to be written, this should be set to 0.

### `DumpData`

Pointer to the miniport-specific data block that is to be appended to the log entry. If no data block is to be written, DumpDataSize should be set to 0, and this field is ignored.

### `StringCount`

The count of null-terminated Unicode strings contained in the StringList member. If no strings are to be written, this should be set to 0.

### `StringList`

The list of null-terminated Unicode strings to be appended to the log entry for use in string substitution. These strings are substituted for the place holders "%2" through "%n" in the log message text when the log entry is being displayed. This list consists of an array of pointers to the null-terminated Unicode strings. StringCount contains the count of string pointers in this array, so no list termination entry is needed. If no strings are to be written, StringCount should be set to 0, and this field is ignored.

## Remarks

Although [StorPortLogError](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogerror) uses **PathId**, **TargetId**, and **LunId** values that are 8bits wide, for [StorPortLogSystemEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogsystemevent) they are 32bits wide. The combined size of the miniport driver's dump data and string areas cannot exceed 150 bytes. This restriction is due to the < 255 byte limit that the kernel enforces on the event log entries.

## See also

[STOR_EVENT_ASSOCIATION_ENUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_event_association_enum)

[StorPortLogSystemEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogsystemevent)