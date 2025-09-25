# ChangerGetParameters function

## Description

**ChangerGetParameters** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_parameters).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

**ChangerGetParameters** returns the STATUS_*XXX* value returned by the system port driver or one of the following values:

STATUS_SUCCESS

STATUS_INFO_LENGTH_MISMATCH

STATUS_INSUFFICIENT_RESOURCES

## Remarks

This routine is required.

**ChangerGetParameters** returns the parameters of a changer, including the number and type of its elements and the functionality it supports.

The changer class driver checks the output buffer length in the I/O stack location before calling **ChangerGetParameters**. If the output buffer length is smaller than **sizeof**([GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)) the changer class driver returns with a value of STATUS_INFO_LENGTH_MISMATCH.

**ChangerGetParameters** retrieves parameter data from the device by building SRBs with CDBs to get the SCSI parameter header page, the element address page, the transport geometry page, and the device capabilities page, or the non-SCSI equivalent of this data.

**ChangerGetParameters** then fills in a GET_CHANGER_PARAMETERS structure at *Irp***->AssociatedIrp.SystemBuffer** before returning to the changer class driver.

## See also

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_GET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_parameters)