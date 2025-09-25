## Description

When a volume arrives in the system, it registers for the MOUNTDEV_MOUNTED_DEVICE_GUID interface class and the mount manager receives a Plug and Play notification. When the mount manager receives this notification, it queries the client driver that manages the volume for the volume's unique ID. In some cases, however, particularly with clusters, the client notifies the mount manager of the arrival of its volume, but then does not respond when queried for the volume's unique ID. The mount manager keeps these volumes in a *dead mounted device* list. Clients can use the IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES IOCTL to request that the mount manager rescan its dead mounted device list and make another attempt to query the clients on the list for the unique IDs of their respective volumes.

This IOCTL is used primarily for cluster support.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

None

### Input buffer length

None

### Output buffer

None

### Output buffer length

None

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

If the operation is successful, the **Status** field is set to STATUS_SUCCESS.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).