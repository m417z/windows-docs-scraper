## Description

The **STORAGE_FIRMWARE_SLOT_INFO** structure contains information about a firmware slot on a storage device.

## Members

### `SlotNumber`

The slot number of the firmware slot.

### `ReadOnly`

Boolean value that indicates whether the firmware slot is read-only. A value of TRUE indicates that the firmware slot is read-only.

### `Reserved[6]`

Reserved for system use.

### `Revision`

Union that contains the firmware revision information.

### `Revision.Info[8]`

Array of eight unsigned characters that contain the firmware revision information in a byte-by-byte format. It can be used to store or read the revision data as an array of bytes.

### `Revision.AsUlonglong`

Unsigned long long integer that represents the firmware revision information as a 64-bit value. It provides a way to access or store the revision information as a single large integer rather than as an array of bytes.

## Remarks

## See also