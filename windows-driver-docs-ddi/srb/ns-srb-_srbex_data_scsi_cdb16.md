# _SRBEX_DATA_SCSI_CDB16 structure (srb.h)

## Description

The **SRBEX_DATA_SCSI_CDB16** structure contains the extended SRB data for a 16-byte SCSI command data block (CDB).

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypeScsiCdb16**.

### `Length`

Length of the data in this structure, in bytes, starting with the **ScsiStatus** member. Set to SRBEX_DATA_SCSI_CDB16_LENGTH.

### `ScsiStatus`

The SCSI status code returned for the submitted SRB.

### `SenseInfoBufferLength`

The length of the sense information returned in the buffer pointed to by **SenseInfoBuffer**.

### `CdbLength`

The length of the CDB data, in bytes, of the **Cdb** array.

### `Reserved`

This member is reserved. Set to 0.

### `Reserved1`

This member is reserved. Set to 0.

### `SenseInfoBuffer`

A pointer to a buffer containing any returned sense information.

### `Cdb`

The 16-byte CDB buffer.

## Remarks

This structure is used to submit an extended SRB data for a CDB of 16 bytes or less.

## See also

[SRBEX_DATA_SCSI_CDB32](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb32)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)