## Description

This IOCTL checks to see if the given volume has a drive letter. If it already has a drive letter, or if the volume has a special mount manager database entry indicating that it does not require a drive letter, this routine returns the current drive letter (if there is one) and does nothing. If the given volume does not have a drive letter and does not have a special mount manager database entry indicating that it does not require a drive letter, the next available drive letter is assigned to the volume. If the volume's nonpersistent device name begins with "\Device\Floppy", the mount manager will check for available drive letters starting with the letter "A." If the volume name begins with "\Device\CdRom" the mount manager will check for available drive letters starting with drive letter "D." In all other cases, the mount manager starts with drive letter "C."

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager client initializes the [**MOUNTMGR_DRIVE_LETTER_TARGET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_drive_letter_target) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**. The client must insert the name of the target volume at the address pointed to by the **DeviceName[]** member of this structure. The target volume name is the name of the nonpersistent device object associated with the volume (for example, "\Device\HarddiskVolume1").

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_DRIVE_LETTER_TARGET)```.

### Output buffer

The mount manager inserts either the current drive letter or the newly assigned drive letter (see previous discussion) in the [**MOUNTMGR_DRIVE_LETTER_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_drive_letter_information) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_DRIVE_LETTER_INFORMATION)```.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

If the operation is successful , the **Status** field is set to STATUS_SUCCESS.

If **InputBufferLength** is less than ```sizeof(MOUNTMGR_DRIVE_LETTER_TARGET)``` or if **OutputBufferLength** is less than ```sizeof(MOUNTMGR_DRIVE_LETTER_INFORMATION)```, the **Status** field is set to STATUS_INVALID_PARAMETER.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTMGR_DRIVE_LETTER_TARGET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_drive_letter_target)