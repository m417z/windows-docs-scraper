# ChangerQueryVolumeTags function

## Description

**ChangerQueryVolumeTags** handles the device-specific aspects of a device-control IRP with the IOCTL code of [IOCTL_CHANGER_QUERY_VOLUME_TAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_query_volume_tags).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

If the changer supports retrieval of volume tag information, **ChangerQueryVolumeTags** returns the STATUS_*XXX* value returned by the system port driver, or one of the following values:

STATUS_SUCCESS

STATUS_INVALID_ELEMENT_ADDRESS

STATUS_INSUFFICIENT_RESOURCES

If the changer does not support retrieval of volume tag information, ChangerQueryVolumeTags returns STATUS_INVALID_DEVICE_REQUEST.

## Remarks

This routine combines the functionality of two SCSI commands: SEND VOLUME TAGS and REQUEST VOLUME ELEMENT ADDRESS. This routine is required.

**ChangerQueryVolumeTags** retrieves volume tag information for specified elements. It can also be used to define or clear volume tag information if the changer supports these operations. The CHANGER_VOLUME_IDENTIFICATION flag in the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure indicates whether the changer supports this functionality.

The changer class driver checks the input and output buffer lengths in the I/O stack location before calling **ChangerQueryVolumeTags**. *Irp***->SystemBuffer** points to a [CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_send_volume_tag_information) structure that indicates the elements, the operation to perform, and a template that specifies the volume ID to search for or to set.

**ChangerQueryVolumeTags** first checks the action code for unsupported operations, and returns STATUS_INVALID_DEVICE_REQUEST for those it does not support. Next, it builds an SRB with a CDB to indicate the device-specific address of the starting element and sends it to the system port driver, passing the volume ID template as a parameter. (For a SCSI changer, the miniclass driver uses the SCSI command SEND VOLUME TAG.)

If the first SRB succeeds, **ChangerQueryVolumeTags** builds a second SRB with a CDB to transfer the results of the previous SRB. (For a SCSI changer, the miniclass driver uses the SCSI command REQUEST VOLUME ELEMENT ADDRESS.)

**ChangerQueryVolumeTags** then fills in a [READ_ELEMENT_ADDRESS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_read_element_address_info) structure at *Irp***->AssociatedIrp.SystemBuffer** that indicates the number of elements for which volume tag information was transferred, and the information for each element.

After filling in the system buffer, **ChangerQueryVolumeTags** sets the **Information** field in the I/O status block to the number of bytes written to the buffer before returning to the changer class driver.

## See also

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status)

[CHANGER_SEND_VOLUME_TAG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_send_volume_tag_information)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[READ_ELEMENT_ADDRESS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_read_element_address_info)