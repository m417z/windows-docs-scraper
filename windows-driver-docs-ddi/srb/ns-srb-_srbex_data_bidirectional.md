# _SRBEX_DATA_BIDIRECTIONAL structure (srb.h)

## Description

The **SRBEX_DATA_BIDIRECTIONAL** structure contains the extended SRB data for bi-directional transfer commands.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypeBidirectional**.

### `Length`

Length of the data in this structure, in bytes, starting with the **DataInTransferLength** member. Set to SRBEX_DATA_BIDIRECTIONAL_LENGTH.

### `DataInTransferLength`

Length of the data present in the **DataInBuffer** member.

### `Reserved1`

This member is reserved. Set to 0.

### `DataInBuffer`

A pointer to the buffer that contains the data sent from the device.

## See also

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)