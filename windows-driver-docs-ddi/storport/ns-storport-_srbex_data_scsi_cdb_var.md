# _SRBEX_DATA_SCSI_CDB_VAR structure (storport.h)

## Description

The **SRBEX_DATA_SCSI_CDB_VAR** structure contains the extended SRB data for a variable length SCSI command data block (CDB).

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypeScsiCdbVar**.

### `Length`

Length of the data in this structure starting with the **ScsiStatus** member. This value ranges between SRBEX_DATA_SCSI_CDB_VAR_LENGTH_MIN and SRBEX_DATA_SCSI_CDB_VAR_LENGTH_MAX.

### `ScsiStatus`

The SCSI status code returned for the submitted SRB.

### `SenseInfoBufferLength`

The length of the sense information returned in the buffer pointed to by **SenseInfoBuffer**.

### `Reserved`

This member is reserved. Contains zeros.

### `CdbLength`

The length of the CDB data, in bytes, of the **Cdb** array.

### `Reserved1`

This member is reserved. Contains zeros.

### `SenseInfoBuffer`

A pointer to a buffer containing any returned sense information.

### `Cdb`

A variable length array containing the CDB buffer.

## Remarks

For CDB data sizes less than 32 bytes, the [SRBEX_DATA_SCSI_CDB32](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb32) structure, and possibly the [SRBEX_DATA_SCSI_CDB16](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb16) structure, may be used instead. The maximum CDB data allowed in the **Cdb** array is SRBEX_DATA_SCSI_CDB_VAR_LENGTH_MAX - SRBEX_DATA_SCSI_CDB_VAR_LENGTH_MIN + 1. The length specified in **CdbLength** must be less than or equal to this value.

## See also

[SRBEX_DATA_SCSI_CDB16](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb16)

[SRBEX_DATA_SCSI_CDB32](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb32)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)