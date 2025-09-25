# IOCTL_EHSTOR_BANDMGMT_CREATE_BAND IOCTL

## Description

New bands are created on a band-managed storage device with the **IOCTL_EHSTOR_BANDMGMT_CREATE_BAND** request. A new band is added to the table of band entries, which includes band location and security properties.

## Parameters

### Major code

### Input buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* must contain an [CREATE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_create_band_parameters) structure followed by the [BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info), [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info), and **AUTH_KEY** structures.

If the **AuthKeyOffset** member of [CREATE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_create_band_parameters) is set to **EHSTOR_BANDMGR_NO_KEY**, the input data in the system buffer need not include an **AUTH_KEY** structure.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (CREATE_BAND_PARAMETERS) + **sizeof**(BAND_LOCATION_INFO) +  **sizeof** (BAND_SECURITY_INFO) + **sizeof**(AUTH_KEY).

### Output buffer

The output buffer at *Irp->AssociatedIrp.SystemBuffer* optionally contains a ULONG value for the identifier of the newly created band.

### Output buffer length

*Parameters.DeviceIoControl.OutputBufferLength* must be at least **sizeof**(ULONG) to receive the band identifier. If return of the band identifier is not wanted, set *Parameters.DeviceIoControl.OutputBufferLength* to 0.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The new band was created. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is invalid. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_CONFLICTING_ADDRESSES | The band was not created due to overlapping locations. |
| STATUS_INSUFFICIENT_RESOURCES | The band was not created because the band table is already full. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

Assigning an authentication key to a newly created band is optional. If no key is provided, where **AuthKeyOffset** = **EHSTOR_BANDMGR_NO_KEY** in the [CREATE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_create_band_parameters) structure, a default authentication key is used. However, this leaves the band vulnerable to another caller who may take control over the band immediately after its creation by changing its authentication key. It is recommended to assign a non-default authentication key to the band at creation time.

The changes made to the band table by this request are committed to the device atomically before the IOCTL request completes. Therefore, it is guaranteed that the band is created with all of its properties set or not created at all should a system or power failure occur.

The location of the new band must not overlap with an existing band or this request will fail with STATUS_CONFLICTING_ADDRESSES.

If the band is unlocked, either the **ReadLock** or **WriteLock** members of [BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info) are set to FALSE, and **CREATEBAND_AUTHKEY_CACHING_ENABLED** is set in the **Flags** member of [CREATE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_create_band_parameters), then credential caching is enabled. The authentication silo driver will cache the band authentication key in memory. This allows the silo driver to automatically authenticate host access to the storage device when volume maintenance is required, such as resizing the band.

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info)

[CREATE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_create_band_parameters)