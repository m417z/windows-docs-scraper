## Description

The **IOCTL_EHSTOR_BANDMGMT_ERASE_ALL_BANDS** request cryptographically erases and resets the authentication keys for all configured bands.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

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
| STATUS_SUCCESS | All bands were successfully erased. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

**IOCTL_EHSTOR_BANDMGMT_ERASE_ALL_BANDS** cryptographically erases and resets the authentication key for each configured band on the storage device, one band at a time. If all configured bands are successfully erased, the IOCTL will return a success status. If erase fails for one or more configured band, the IOCTL will return the failure status from the first configured band for which an error occurred. In this case, a client should fall back to calling [**IOCTL_EHSTOR_BANDMGMT_ERASE_BAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band) for each configured band.

There is no atomicity guarantee provided for erasure across multiple configured bands. Thus, if a system or power failure occurs while this IOCTL is being processed, some configured bands might have been successfully erased while others might not have.

## See also

[**IOCTL_EHSTOR_BANDMGMT_ERASE_BAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_erase_band)