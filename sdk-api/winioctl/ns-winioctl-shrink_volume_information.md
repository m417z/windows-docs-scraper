# SHRINK_VOLUME_INFORMATION structure

## Description

Specifies the volume shrink operation to perform.

## Members

### `ShrinkRequestType`

Indicates the operation to perform. The valid values are as follows.

| Value | Meaning |
| --- | --- |
| **ShrinkPrepare** | Volume should perform any steps necessary to prepare for a shrink operation. |
| **ShrinkCommit** | Volume should commit the shrink operation changes. |
| **ShrinkAbort** | Volume should terminate the shrink operation. |

### `Flags`

This member must be zero.

### `NewNumberOfSectors`

The number of sectors that should be in the shrunken volume. Used only when the **ShrinkRequestType** member is **ShrinkPrepare**, otherwise this member should be initialized to zero.

## See also

[FSCTL_SHRINK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_shrink_volume)