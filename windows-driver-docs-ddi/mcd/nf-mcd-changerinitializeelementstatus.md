# ChangerInitializeElementStatus function

## Description

**ChangerInitializeElementStatus** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_initialize_element_status).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

**ChangerInitializeElementStatus** returns the status returned by the system port driver or one of the following values:

STATUS_SUCCESS

STATUS_INVALID_PARAMETER

STATUS_INSUFFICIENT_RESOURCES

If the changer does not support initializing a range of elements of a particular type and ChangerInitializeElementStatus is called with an element type other than AllElements, it returns STATUS_INVALID_PARAMETER.

## Remarks

This routine is required.

**ChangerInitializeElementStatus** updates the changer's internal memory with current information about its elements.

The changer class driver checks the input buffer length in the I/O stack location before calling **ChangerInitializeElementStatus**.

*Irp***->SystemBuffer** points to a [CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_initialize_element_status) structure as an input parameter that indicates the elements for which to initialize status and whether to initialize element status with data obtained from bar code labels.

For a SCSI changer, **ChangerInitializeElementStatus** builds an SRB with a CDB to initialize element status, translates zero-based element addresses to device-specific addresses, and sends the SRB to the system port driver.

**ChangerInitializeElementStatus** sets the **Information** field in the I/O status block to **sizeof**(CHANGER_INITIALIZE_ELEMENT_STATUS) before returning to the changer class driver.

## See also

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list)

[CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_initialize_element_status)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)