# ChangerExchangeMedium function

## Description

**ChangerExchangeMedium** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_exchange_medium).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

If the changer supports exchanging media, **ChangerExchangeMedium** returns the status returned by the system port driver, or one of the following values:

STATUS_SUCCESS

STATUS_DESTINATION_ELEMENT_FULL

STATUS_INVALID_ELEMENT_ADDRESS

STATUS_SOURCE_ELEMENT_EMPTY

If the changer does not support exchanging media, ChangerExchangeMedium returns STATUS_INVALID_DEVICE_REQUEST.

## Remarks

This routine is required.

**ChangerExchangeMedium** moves a piece of media from a source element to one destination and from that destination to another destination. The source and second destination are often the same, resulting in a simple exchange of media.

The CHANGER_EXCHANGE_MEDIA flag in **Features0** of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure indicates whether the changer supports this functionality. A changer that supports exchanging media typically has two picker mechanisms on a single transport element, or at least two transport elements. A changer that has a single picker mechanism might support exchanging medium through emulation of the command.

The changer class driver checks the input buffer length in the I/O stack location before calling a miniclass driver's **ChangerExchangeMedium** routine. *Irp***->SystemBuffer** points to a [CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_exchange_medium) structure as an input parameter that indicates the transport element and the destination to set.

**ChangerExchangeMedium** first verifies that the transport, source, and destination element addresses are valid, then converts zero-based element addresses to device-specific element addresses. It then builds an SRB with a CDB to exchange the media and sends it to the system port driver.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_exchange_medium)

[ChangerMoveMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changermovemedium)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)