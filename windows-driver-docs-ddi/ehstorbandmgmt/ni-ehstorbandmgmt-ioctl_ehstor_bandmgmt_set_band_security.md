# IOCTL_EHSTOR_BANDMGMT_SET_BAND_SECURITY IOCTL

## Description

The security properties of bands in a band-managed storage device are modified with the **IOCTL_EHSTOR_BANDMGMT_SET_BAND_SECURITY** request.

## Parameters

### Major code

### Input buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* must contain a  [SET_BAND_SECURITY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_security_parameters) structure followed by the **AUTH_KEY** and [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) structures.

If the **AuthKeyOffset** member of [SET_BAND_SECURITY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_security_parameters) is set to **EHSTOR_BANDMGR_NO_KEY**, the input data in the system buffer need not include an **AUTH_KEY** structure. Also, if a new authentication key is not given, no updated key structure is included.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (SET_BAND_SECURITY_PARAMETERS) + 2 * **sizeof**(AUTH_KEY) + **sizeof**(BAND_SECURITY_INFO) when all input structures are required.

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
| STATUS_SUCCESS | Security properties for the band were changed. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is invalid. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_NOT_FOUND | A band was not found for the selection criteria provided. |
| STATUS_ACCESS_DENIED | The authentication key provided is not valid. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

Read and write locking and unlocking for bands are set with this IOCTL in the [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) structure included as input in the system buffer.

Authentication key changes will not affect the lock state of the band. It is not necessary to unmount a volume to change an authentication key with this request.

When a band is unlocked, meaning either the **Readlock** or **WriteLock** members of [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) are FALSE, the silo driver will cache the provided authentication key if **SETBANDSEC_AUTHKEY_CACHING_ENABLED** is set in the **Flags** member of [SET_BAND_SECURITY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_security_parameters).

As a special case, this IOCTL can be used to notify the silo driver that a band was unlocked without the use of the locking members in [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info). To do this, the **NewAuthKeyOffset** member of [SET_BAND_SECURITY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_security_parameters) is set to **CurrentAuthKeyOffset** with **BandSecurityInfoOffset** set to 0. In this case, no security changes occur, but the key provided at **CurrentAuthKeyOffset** is cached in memory, provided that **SETBANDSEC_AUTHKEY_CACHING_ENABLED** is set in **Flags**.

The changes made to the band table by this request are committed to the device atomically before the IOCTL request completes. Therefore, it is guaranteed that the band is modified with all of its properties set or no properties set at all should a system or power failure occur.

## See also

[BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info)

[IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band)

[SET_BAND_SECURITY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_security_parameters)