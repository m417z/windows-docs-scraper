# IOCTL_HID_ENABLE_SECURE_READ IOCTL

## Description

The IOCTL_HID_ENABLE_SECURE_READ request enables a secure read for open files of a [HID collection](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections). Only a "trusted" user-mode application (an application with SeTcbPrivilege privileges) can successfully use this request. Kernel-mode drivers have SeTcbPrivilege privileges by default, but user-mode applications do not.

A client uses an [IOCTL_HID_DISABLE_SECURE_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_disable_secure_read) request to cancel an enable secure read request.

For information about how to use enable and disable secure read requests to enforce a secure read for a collection, see [Enforcing a Secure Read For a HID Collection](https://learn.microsoft.com/windows-hardware/drivers/hid/enforcing-a-secure-read-for-a-hid-collection).

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

The HID class driver sets the **Status** field of **Irp->IoStatus** to STATUS_SUCCESS if the requester has SeTcbPrivilege privileges and the file is valid. Otherwise, it sets the **Status** field to STATUS_PRIVILEGE_NOT_HELD.

## See also

[IOCTL_HID_DISABLE_SECURE_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_disable_secure_read)