# IOCTL_EHSTOR_BANDMGMT_DELETE_BAND IOCTL

## Description

A configured band on a storage device is deleted with the **IOCTL_EHSTOR_BANDMGMT_DELETE_BAND** request. An erase option in the input parameters allows the request to perform a cryptographic erase of the band data.

## Parameters

### Major code

### Input buffer

The input buffer at *Irp->AssociatedIrp.SystemBuffer* must contain a [DELETE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_delete_band_parameters) and possibly an **AUTH_KEY** structure.

If the **AuthKeyOffset** member of [DELETE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_delete_band_parameters) is set to **EHSTOR_BANDMGR_NO_KEY**, the input data in the system buffer need not include an **AUTH_KEY** structure.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (DELETE_BAND_PARAMETERS) + **sizeof**(AUTH_KEY).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The band was successfully deleted. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is incorrect. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_ACCESS_DENIED | The authentication key is invalid or band is locked for writing. |
| STATUS_NOT_FOUND | The band was not found for the selection criteria provided. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

An authentication key is required to delete a band without performing an erase first. To request a band erase, the **DELBAND_ERASE_BEFORE_DELETE** flag is set in the **Flags** member of [DELETE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_delete_band_parameters).

After a band delete, all LBAs contained in the deleted band are returned to the global band. The locking conditions for the global band now apply to the LBAs returned to the global band. The LBAs returned to the global band are now associated with the media key for the global band and encrypted data in those LBAs is unrecoverable.

The deleted band remains in the silo driver's band table but becomes unconfigured. The authentication key is reset to the default value, band and key metadata contains zeros, and the lock states revert to **PERSISTENT_UNLOCK**. The band is now available for reconfiguration with an [IOCTL_EHSTOR_BANDMGMT_CREATE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_create_band) request.

Deleting a band without a cryptographic erase will not remove the encryption key for that band. It is possible to later create a band with the same configuration and band identifier as the deleted band. In this case, data previously stored in the band and not overwritten since the deletion of the previous band will be available. To avoid this situation, delete the band with the **DELBAND_ERASE_BEFORE_DELETE** flag set in [DELETE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_delete_band_parameters).

The **IOCTL_EHSTOR_BANDMGMT_DELETE_BAND** will not delete the global band. A request to do so will return **STATUS_INVALID_PARAMETER**.

## See also

[DELETE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_delete_band_parameters)

[IOCTL_EHSTOR_BANDMGMT_CREATE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_create_band)

[IOCTL_EHSTOR_BANDMGMT_ERASE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band)