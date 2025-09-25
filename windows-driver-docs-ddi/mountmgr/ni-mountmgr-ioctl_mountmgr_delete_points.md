## Description

This IOCTL is identical in input and output to [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points). The difference is that IOCTL_MOUNTMGR_DELETE_POINTS has the side effect of deleting the symbolic links and the mount manager database entries for the triples returned.

If the input to this IOCTL is ("\DosDevices\X:", NULL, NULL) where X is the current drive letter for the volume indicated in the input triple, the mount manager adds a special entry to its database indicating that the client does not require a drive letter. On subsequent reboots, the mount manager will not assign a default drive letter to the volume.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

See [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points).

### Input buffer length

See [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points).

### Output buffer

See [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points).

### Output buffer length

See [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points).

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

See [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points).

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points)