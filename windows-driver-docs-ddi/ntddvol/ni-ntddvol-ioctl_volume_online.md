# IOCTL_VOLUME_ONLINE IOCTL

## Description

The **IOCTL_VOLUME_ONLINE** IOCTL puts the volume in an ONLINE state, which is a state where read and write operations will be executed. The requests are passed down to the physical disk until a subsequent [IOCTL_VOLUME_OFFLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_offline) is received.

A common use for **IOCTL_VOLUME_ONLINE** is a case in which the mount manager automatically puts a new volume in the ONLINE state when the volume arrives, unless that volume is listed in a registry key that is populated by the cluster service. **IOCTL_VOLUME_ONLINE** is called for removable drives regardless of the NoAutoMount setting in the following registry key:

HKCU\System\CurrentControlSet\Services\Mountmgr\NoAutoMount

But for volumes controlled by NoAutoMount, assigning a drive letter will cause **IOCTL_VOLUME_ONLINE** to be called.

For volumes that are controlled by the cluster service, **IOCTL_VOLUME_ONLINE** is sent by the cluster service when the local node owns the volume. The cluster service uses both **IOCTL_VOLUME_ONLINE** and **IOCTL_VOLUME_ONLINE** to allow I/O to a disk volume when the disk volume is owned by the local server. Until the cluster service puts the disk volume in an ONLINE state, no I/O is permitted to the disk volume. This prevents disk volume corruption that could result from multiple cluster nodes writing to the same disk volume simultaneously.

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

[IOCTL_VOLUME_OFFLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_offline)