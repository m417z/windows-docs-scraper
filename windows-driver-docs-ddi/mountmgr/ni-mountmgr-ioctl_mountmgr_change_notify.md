## Description

Clients send this IOCTL to the mount manager to be informed whenever there is a change in the mount manager's persistent symbolic link name database.

The mount manager maintains a counter called **EpicNumber** that records how many changes have occurred in its persistent name database since the last startup. Clients send a number to the mount manager with every change notification request IRP, and the mount manager responds in the following manner:

* If the number supplied by the client is not equal to **EpicNumber**, the mount manager returns STATUS_SUCCESS, indicating that changes have occurred since the client last compared its number with the mount manager's **EpicNumber**.

* If the number supplied by the client is equal to **EpicNumber**, the mount manager interprets this as a request to be informed of the next change to the persistent name database, and it queues the change notification IRP and returns STATUS_PENDING. Whenever a change occurs in the database, the mount manager completes all of the pending change notification IRPs, thereby informing clients of the change.

A client that only wants to be informed of the changes to a particular volume is advised to register for Plug and Play target device notification and watch for GUID_IO_VOLUME_NAME_CHANGE.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager client initializes the [**MOUNTMGR_CHANGE_NOTIFY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_change_notify_info) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_CHANGE_NOTIFY_INFO)```.

### Output buffer

The mount manager returns the current **EpicNumber** in the [**MOUNTMGR_CHANGE_NOTIFY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_change_notify_info) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

None.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

If the operation is successful, the **Status** field is set to STATUS_SUCCESS and the **Information** field is set to ```sizeof(MOUNTMGR_CHANGE_NOTIFY_INFO)```.

If **InputBufferLength** is less than ```sizeof(MOUNTMGR_CHANGE_NOTIFY_INFO)``` or **OutputBufferLength** is less than ```sizeof(MOUNTMGR_CHANGE_NOTIFY_INFO)```, the **Status** field is set to STATUS_INVALID_PARAMETER.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTMGR_CHANGE_NOTIFY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_change_notify_info)