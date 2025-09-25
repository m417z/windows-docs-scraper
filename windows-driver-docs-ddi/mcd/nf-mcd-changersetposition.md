# ChangerSetPosition function

## Description

**ChangerSetPosition** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_position).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

If the changer supports setting the position of the transport element, **ChangerSetPosition** returns the status returned by the system port driver, or one of the following values:

STATUS_SUCCESS

STATUS_INFO_LENGTH_MISMATCH

STATUS_INVALID_PARAMETER

STATUS_INSUFFICIENT_RESOURCES

If the changer does not support setting the position of the transport element, ChangerSetPosition returns STATUS_INVALID_DEVICE_REQUEST.

## Remarks

This routine is required.

**ChangerSetPosition** sets the changer's robotic transport mechanism to the specified destination, typically to optimize moving or exchanging media by first positioning the transport.

The CHANGER_POSITION_TO_ELEMENT flag in **Features0** of [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) indicates whether the changer supports this functionality.

The changer class driver checks the input buffer length in the I/O stack location before calling **ChangerSetPosition**. *Irp***->SystemBuffer** points to a [CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_position) structure as an input parameter that indicates the transport element and the destination to set.

**ChangerSetPosition** first verifies that the transport and destination element addresses are valid and converts zero-based element addresses to device-specific addresses. It then builds an SRB with a CDB to position the element and sends it to the system port driver.

**ChangerSetPosition** sets the **Information** field in the I/O status block to **sizeof**(CHANGER_SET_POSITION) before returning to the changer class driver.

## See also

[, IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_position)

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_position)