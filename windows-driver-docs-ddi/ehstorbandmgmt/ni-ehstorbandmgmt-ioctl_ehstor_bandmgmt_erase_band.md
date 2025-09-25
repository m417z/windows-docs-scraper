# IOCTL_EHSTOR_BANDMGMT_ERASE_BAND IOCTL

## Description

The **IOCTL_EHSTOR_BANDMGMT_ERASE_BAND** request cryptographically erases and resets the authentication key of a band. The remaining configuration of the band is left unmodified.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** must contain an [**ERASE_BAND_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_erase_band_parameters) and possibly an **AUTH_KEY** structure.

If the **NewAuthKeyOffset** member of [**ERASE_BAND_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_erase_band_parameters) is set to **EHSTOR_BANDMGR_NO_KEY**, the input data in the system buffer need not include an **AUTH_KEY** structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the buffer, which must be at least ```sizeof(ERASE_BAND_PARAMETERS) + sizeof(AUTH_KEY)```.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

None.

### Input/output buffer length

None.

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| ------------ | ----------- |
| STATUS_SUCCESS | The band was successfully erased. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is incorrect. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_ACCESS_DENIED | The erase authentication key is not a default key and the band cannot be erased. |
| STATUS_NOT_FOUND | The band was not found for the selection criteria provided. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

A current erase authentication key is not provided in an **IOCTL_EHSTOR_BANDMGMT_ERASE_BAND** request. The erase authentication key for the storage device is previously configured.

No method is provided in Windows to change the erase authentication key for a storage device. Provided that the correct parameters are given as input in the system buffer, this request should succeed. If the erase authentication key was changed outside of Windows, such as in a dual-boot environment with a different operating system, this request may fail.

When a band is erased with **IOCTL_EHSTOR_BANDMGMT_ERASE_BAND**, the only prior properties that remain are band start and band size. The previous media encryption key is removed and a new key is generated. Locking is set to **PERSISTANT_UNLOCK** for both reading and writing. Security metadata previously set is erased. The new authentication key specified in [**ERASE_BAND_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_erase_band_parameters) is set unless use of the default key is indicated.

To prevent other applications from taking control of a band and erase by using the default key, a new authentication key should be included with the **IOCTL_EHSTOR_BANDMGMT_ERASE_BAND** request.

The changes made to the band table by this request are committed to the device atomically before the IOCTL request completes. Therefore, it is guaranteed that the band is modified with all of its properties set or no properties set at all should a system or power failure occur.

## See also

[**ERASE_BAND_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_erase_band_parameters)

[**IOCTL_EHSTOR_BANDMGMT_DELETE_BAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band)

[**IOCTL_EHSTOR_BANDMGMT_ERASE_ALL_BANDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_all_bands)