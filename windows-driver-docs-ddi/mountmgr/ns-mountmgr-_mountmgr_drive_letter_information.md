## Description

The **MOUNTMGR_DRIVE_LETTER_INFORMATION** structure is used by the mount manager to furnish a drive letter to a client that has requested a driver letter by means of an [**IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_next_drive_letter) request.

## Members

### `DriveLetterWasAssigned`

Indicates when TRUE that member **CurrentDriveLetter** contains a drive letter. When FALSE, a driver letter was not assigned to the device.

### `CurrentDriveLetter`

Contains either an existing or a newly assigned drive letter in the form of a single ASCII character (for example, "D") if **DriveLetterWasAssigned** is TRUE.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_next_drive_letter)