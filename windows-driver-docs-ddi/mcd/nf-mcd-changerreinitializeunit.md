# ChangerReinitializeUnit function

## Description

**ChangerReinitializeUnit** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_REINITIALIZE_TRANSPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_reinitialize_transport).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

If the changer supports recalibrating a transport element, **ChangerReinitializeUnit** returns the STATUS_*XXX* value returned by the system port driver, or one of the following values:

STATUS_SUCCESS

STATUS_INVALID_ELEMENT_ADDRESS

STATUS_INVALID_PARAMETER

STATUS_INSUFFICIENT_RESOURCES

If the changer does not support recalibrating a transport element, ChangerReinitializeUnit returns STATUS_INVALID_DEVICE_REQUEST.

## Remarks

This routine is required.

**ChangerReinitializeUnit** causes the changer to recalibrate its transport element. Depending on the changer, this may return the transport to a "home" position. The changer class driver typically calls **ChangerReinitializeUnit** after the changer has been powered on or a calling application has initiated a recovery operation. The CHANGER_DEVICE_REINITIALIZE_CAPABLE flag in **Features0** of [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) indicates whether the changer's transport supports recalibration in those circumstances.

The changer class driver checks the input buffer length in the I/O stack location before calling **ChangerReinitializeUnit**. *Irp***->SystemBuffer** points to a [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) structure that indicates the element to recalibrate.

**ChangerReinitializeUnit** builds an SRB with a CDB to position the transport element and sends it to the system port driver.

**ChangerReinitializeUnit** sets the **Information** field in the I/O status block to **sizeof**(CHANGER_ELEMENT) before returning to the changer class driver.

## See also

[IOCTL_CHANGER_REINITIALIZE_TRANSPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_reinitialize_transport)

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)