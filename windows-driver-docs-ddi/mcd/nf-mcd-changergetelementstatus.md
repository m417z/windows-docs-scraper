# ChangerGetElementStatus function

## Description

**ChangerGetElementStatus** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

**ChangerGetElementStatus** returns the status returned by the system port driver or one of the following values:

STATUS_SUCCESS

STATUS_INFO_LENGTH_MISMATCH

STATUS_INSUFFICIENT_RESOURCES

STATUS_INVALID_DEVICE_REQUEST

STATUS_INVALID_ELEMENT_ADDRESS

If VolumeTagInfo is set for a changer that does not support volume tag information, ChangerGetElementStatus returns STATUS_INVALID_PARAMETER.

## Remarks

This routine is required.

**ChangerGetElementStatus** returns the status and, optionally, volume tag information for all elements in a changer, or the status of a specific number of elements of a particular type.

The changer class driver checks the input and output buffer lengths in the I/O stack location before calling **ChangerGetElementStatus**.

*Irp***->SystemBuffer** points to a [CHANGER_READ_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_read_element_status) structure as an input parameter that indicates the elements for which to report status and whether to report volume tag information.

**ChangerGetElementStatus** first builds an SRB with a CDB to read element status command and sends it to the system port driver to retrieve the status of the changer's elements. For most element types, **ChangerGetElementStatus** then fills in a [CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status) structure at *Irp***->AssociatedIrp.SystemBuffer** for each element for which it reports status. However, some elements of type **ChangerDrive** return product information data. If the device provides product information, the miniclass driver must report the element status data in a structure of type [CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status_ex) instead of using CHANGER_ELEMENT_STATUS. **ChangerGetElementStatus** must indicate that product information is present by setting ELEMENT_STATUS_PRODUCT_DATA in the **Flags** member of the structure.

**ChangerGetElementStatus** sets the **Information** field in the I/O status block to the number of bytes returned before returning to the changer class driver.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list)

[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status)

[CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status_ex)

[CHANGER_READ_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_read_element_status)

[ChangerGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetstatus)

[ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus)

[ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags)

[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status)