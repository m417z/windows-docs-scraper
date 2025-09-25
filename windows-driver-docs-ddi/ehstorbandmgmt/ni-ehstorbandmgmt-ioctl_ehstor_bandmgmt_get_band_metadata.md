# IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA IOCTL

## Description

Metadata associated with a band is retrieved with an  **IOCTL_EHSTOR_BANDMGMT_GET_BAND_METADATA** request. The metadata for a band serves as a data area for a key manager application.

## Parameters

### Major code

### Input buffer

The input buffer at *Irp->AssociatedIrp.SystemBuffer* must contain a  [GET_BAND_METADATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_get_band_metadata_parameters) structure.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (GET_BAND_METADATA_PARAMETERS).

### Output buffer

The output buffer at *Irp->AssociatedIrp.SystemBuffer* contains a byte array of band metadata specified by [GET_BAND_METADATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_get_band_metadata_parameters).

### Output buffer length

The length of a [GET_BAND_METADATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_get_band_metadata_parameters) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The metadata was returned in the system buffer. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer size is incorrect. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_NOT_FOUND | The band was not found for the selection criteria provided. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

Authentication for this IOCTL is unnecessary and an authentication key is not included as input.

## See also

[BAND_LOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_location_info)

[BAND_SECURITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_security_info)

[CREATE_BAND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_create_band_parameters)