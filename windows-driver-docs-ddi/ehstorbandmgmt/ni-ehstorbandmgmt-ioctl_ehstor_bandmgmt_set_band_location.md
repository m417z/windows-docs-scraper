# IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION IOCTL

## Description

The location properties of bands in a band-managed storage device are modified with the **IOCTL_EHSTOR_BANDMGMT_SET_BAND_LOCATION** request.

## Parameters

### Major code

### Input buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* must contain a [SET_BAND_LOCATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_location_parameters) structure followed by the **AUTH_KEY** and [BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info) structures.

If the **AuthKeyOffset** member of [SET_BAND_LOCATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_location_parameters) is set to **EHSTOR_BANDMGR_NO_KEY**, the input data in the system buffer need not include an **AUTH_KEY** structure.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (SET_BAND_LOCATION_PARAMETERS) + **sizeof**(AUTH_KEY) + **sizeof**(BAND_LOCATION_INFO).

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
| STATUS_SUCCESS | The location properties for the band were changed. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is invalid. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_NOT_FOUND | The band was not found for the selection criteria provided. |
| STATUS_ACCESS_DENIED | The authentication key provided is not valid. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

Data in LBAs that remains after resizing is not modified by the operation. Also, it is unnecessary to unmount a volume during a resize operation if the LBA range that spans the volume remains within the band after resizing.

The changes made to the band table by this request are committed to the device atomically before the IOCTL request completes. Therefore, it is guaranteed that the band is modified with all of its properties set or no properties set at all should a system or power failure occur.

The **BandSize** member of [BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info) must be greater than 0. This IOCTL cannot resize a band to 0 to cause a band deletion. To delete a band, the [IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band) request is used.

If [BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info) specifies properties for the global band, **BandStart** must be set to 0 and **BandSize** must be set to –1.

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[IOCTL_EHSTOR_BANDMGMT_DELETE_BAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_delete_band)

[SET_BAND_LOCATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_location_parameters)