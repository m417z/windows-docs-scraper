# ChangerSetAccess function

## Description

**ChangerSetAccess** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_access).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

If the changer supports setting access, **ChangerSetAccess** returns the STATUS_*XXX* value returned by the system port driver or one of the following values:

STATUS_SUCCESS

STATUS_INSUFFICIENT_RESOURCES

STATUS_INVALID_PARAMETER

If the changer does not support setting access, ChangerSetAccess returns STATUS_INVALID_DEVICE_REQUEST.

## Remarks

This routine is required.

**ChangerSetAccess** locks or unlocks a changer's IEport, door, or keypad, and extends or retracts an IEport.

The changer class driver checks the input buffer length in the I/O stack location before calling **ChangerSetAccess**. *Irp***->SystemBuffer** points to a [CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_access) structure as an input parameter that indicates the element to set and the operation to perform.

**ChangerSetAccess** first checks for unsupported elements and operations, and returns the appropriate status code for those it doesn't support.

Next, **ChangerSetAccess** translates the zero-based element address passed by the system to the device-specific element address required by the changer.

Finally, **ChangerSetAccess** builds an SRB with a CDB for the given operation on the given element and sends it to the system port driver. The command to use depends on the changer. For example, the Exabyte miniclass driver uses the SCSI command PREVENT ALLOW MEDIUM REMOVAL to lock or unlock a changer door and MOVE MEDIUM to extend or retract an IEport.

## See also

[CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_access)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_access)