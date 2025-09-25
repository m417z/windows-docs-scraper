# IOCTL_HID_DISABLE_SECURE_READ IOCTL

## Description

The IOCTL_HID_DISABLE_SECURE_READ request cancels an [IOCTL_HID_ENABLE_SECURE_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_enable_secure_read) request for a [HID collection](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections). Only a "trusted" user-mode application (an application with SeTcbPrivilege privileges) can successfully use this request. Kernel-mode drivers have SeTcbPrivilege privileges by default, but user-mode applications do not.

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

The HID class driver sets the **Status** member of **Irp->IoStatus** to STATUS_SUCCESS if the requester has SeTcbPrivilege privileges and the file is valid. Otherwise, it is set to STATUS_PRIVILEGE_NOT_HELD.

## See also

[IOCTL_HID_DISABLE_SECURE_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_disable_secure_read)