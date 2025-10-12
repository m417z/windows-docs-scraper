# ChangerMoveMedium function

## Description

**ChangerMoveMedium** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_move_medium).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

**ChangerMoveMedium** returns the status returned by the system port driver, or one of the following values:

STATUS_SUCCESS

STATUS_DESTINATION_ELEMENT_FULL

STATUS_INVALID_ELEMENT_ADDRESS

STATUS_INVALID_DEVICE_REQUEST

STATUS_INVALID_PARAMETER

STATUS_INSUFFICIENT_RESOURCES

STATUS_SOURCE_ELEMENT_EMPTY

## Remarks

This routine is required.

**ChangerMoveMedium** moves a piece of media from one element to another.

The changer class driver checks the input buffer length in the I/O stack location before calling **ChangerMoveMedium**. *Irp***->SystemBuffer** points to a [CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_move_medium) structure that indicates the transport element, the source, the destination, and whether to flip the medium.

**ChangerMoveMedium** first verifies that the transport, source, and destination element addresses are valid and then converts zero-based element addresses to device-specific addresses. It then builds an SRB with a CDB to move the piece of media and sends it to the system port driver.

**ChangerMoveMedium** sets the **Information** field in the I/O status block to **sizeof**(CHANGER_MOVE_MEDIUM) before returning to the changer class driver.

## See also

[IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_move_medium)

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_move_medium)

[ChangerExchangeMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerexchangemedium)