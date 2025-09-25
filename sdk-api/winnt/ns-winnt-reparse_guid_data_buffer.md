# REPARSE_GUID_DATA_BUFFER structure

## Description

Contains information about a reparse point. It is used by the
[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_reparse_point) control code.

## Members

### `ReparseTag`

The reparse point tag. This member identifies the structure of the user-defined reparse data. For more
information, see [Reparse Point Tags](https://learn.microsoft.com/windows/desktop/FileIO/reparse-point-tags).

### `ReparseDataLength`

The size of the reparse data in the **DataBuffer** member, in bytes. This value may
vary with different tags and may vary between two uses of the same tag.

### `Reserved`

Reserved; do not use.

### `ReparseGuid`

A **GUID** that uniquely identifies the reparse point. When setting a reparse
point, the application must provide a non-NULL **GUID** in the
**ReparseGuid** member. When retrieving a reparse point from the file system,
**ReparseGuid** is the **GUID** assigned when the reparse point
was set.

### `GenericReparseBuffer`

### `GenericReparseBuffer.DataBuffer`

The user-defined data for the reparse point. The contents are determined by the reparse point implementer.
The tag in the **ReparseTag** member and the **GUID** in the
**ReparseGuid** member indicate how the data is to be interpreted.

## Remarks

The **REPARSE_GUID_DATA_BUFFER** structure is
used by all third-party layered drivers to store data for a reparse point. Each reparse point contains one
instance of a **REPARSE_GUID_DATA_BUFFER**
structure.

## See also

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_reparse_point)

[Reparse Points](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points)