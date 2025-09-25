# _SRBEX_DATA_WMI structure (srb.h)

## Description

The **SRBEX_DATA_WMI** structure contains the request data for an extended WMI SRB.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypeWmi**.

### `Length`

Length of the data in this structure starting with the **WMISubFunction** member. Set to SRBEX_DATA_WMI_LENGTH.

### `WMISubFunction`

Indicates the WMI action to be performed. The subfunction value corresponds to the WMI minor IRP number that identifies the WMI operation.

### `WMIFlags`

Indicates that the WMI request is for the adapter if SRB_WMI_FLAGS_ADAPTER_REQUEST is set and that storage device address is reserved. Otherwise, *WMIFlags* will be **NULL**, indicating that the request is for the storage device specified by an address at **AddressOffset** in the [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block) structure.

### `Reserved`

This member is reserved. Contains zeros.

### `Reserved1`

This member is reserved. Set to 0.

### `DataPath`

Specifies the WMI data path for this request.

## See also

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)