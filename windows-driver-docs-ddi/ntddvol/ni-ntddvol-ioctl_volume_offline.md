# IOCTL_VOLUME_OFFLINE IOCTL

## Description

The **IOCTL_VOLUME_OFFLINE** IOCTL puts the volume in an OFFLINE state, which is a state where read and write operations will fail. The requests will not be passed down to the physical disk until a subsequent [IOCTL_VOLUME_ONLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_online) is received.

A common use for **IOCTL_VOLUME_OFFLINE** is a case in which one application or driver wants to prevent a volume from being remounted by a call to open the volume from a second application or driver while the volume is in the process of being removed by the first application or driver. For example, before masking a Logical Unit Number (LUN), the volumes on the LUN should be locked (optional), dismounted, taken offline, and uninstalled. Now the LUN can be masked without causing Plug and Play (PnP) surprise removal events to be logged for the volumes and the disk itself. Without the call to take the volume offline, after the handle that is used to dismount it is closed, the volume can then be remounted by a call to open it from another application or driver, if it occurred before the call to uninstall the volume. A call to open a volume succeeds on an offline volume, but I/O directed toward an offline volume fails. Taking a volume offline has no effect on disk I/O (if the application or driver opened a handle to the disk), but stops volume I/O (if the application or driver opened a handle to the volume).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** member is set to STATUS_SUCCESS.

## See also

[IOCTL_VOLUME_ONLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_online)