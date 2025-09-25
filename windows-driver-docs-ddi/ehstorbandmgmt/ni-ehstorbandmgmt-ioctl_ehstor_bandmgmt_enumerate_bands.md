# IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS IOCTL

## Description

This **IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS** request is sent to retrieve the list of bands for a storage device under band management. Banding information is returned in a table of band entries that includes band location and security properties.

## Parameters

### Major code

### Input buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* must contain an [ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters) structure.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (ENUMERATE_BANDS_PARAMETERS).

### Output buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* contains a [BAND_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table) structure followed by **BandTableEntryCount** band entries.

### Output buffer length

The length of a [BAND_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table) structure followed by **BandTableEntryCount** band entries.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | Security features on the storage device were deactivated. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is invalid. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_NOT_FOUND | No bands are configured for the enumeration parameters provided. |
| STATUS_BUFFER_OVERFLOW | A buffer is not provided or its size set to zero. The required size is returned in the **Information** field. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |
| STATUS_BUFFER_TOO_SMALL | The output buffer supplied is not large enough to hold the output data returned. |

## Remarks

A driver or application can query for the necessary output buffer size by setting the output buffer for the request to NULL and the output size to 0. The **IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS** request will return with the **Status** field of the *IoStatus* block set to STATUS_BUFFER_OVERFLOW and the **Information** field will contain the required buffer size.

## See also

[BAND_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table)

**ENUMERATE_BANDS_PARAMETERS**