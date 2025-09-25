# ChangerGetStatus function

## Description

**ChangerGetStatus** handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_status).

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

**ChangerGetStatus** returns the STATUS_*XXX* value returned by the system port driver. If there is not enough memory to process the request or to process the STATUS_*XXX* value returned by the system port driver **ChangerGetStatus** returns STATUS_INSUFFICIENT_RESOURCES.

## Remarks

This routine is required.

**ChangerGetStatus** indicates whether the changer is able to accept requests.

**ChangerGetStatus** builds an SRB with a CDB to get the changer's status (using the SCSI command TEST UNIT READY or non-SCSI equivalent) and sends it to the system port driver to obtain status of the changer.

## See also

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[IOCTL_CHANGER_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_status)