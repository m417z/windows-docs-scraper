# IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA IOCTL

## Description

Metadata associated with a band is set with an **IOCTL_EHSTOR_BANDMGMT_SET_BAND_METADATA** request. The metadata for a band serves as a data area for a key manager application.

## Parameters

### Major code

### Input buffer

The input buffer at *Irp->AssociatedIrp.SystemBuffer* must contain a [SET_BAND_METADATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_metadata_parameters) and possibly an **AUTH_KEY** structure along with the new metadata to set for the band.

If the **AuthKeyOffset** member of [SET_BAND_METADATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_metadata_parameters) is set to **EHSTOR_BANDMGR_NO_KEY**, the input data in the system buffer need not include an **AUTH_KEY** structure.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer, which must be at least **sizeof** (SET_BAND_METADATA_PARAMETERS) + **MetadataSize** + **sizeof**(AUTH_KEY).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values may be returned in the **Status** field:

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The metadata was set for the selected band. |
| STATUS_INVALID_DEVICE_REQUEST | Storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is incorrect. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_NOT_FOUND | Band was not found for the selection criteria provided. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |

## Remarks

Metadata can also be erased by using this IOCTL. To erase metadata for a band, set the metadata portion of input buffer to all zeros or some other erase pattern. To ensure removal of sensitive information in metadata blobs, this erase operation should be performed prior to deleting a band from the silo driver's band table.

## See also

[SET_BAND_METADATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_set_band_metadata_parameters)