# _SRBEX_DATA_PNP structure (storport.h)

## Description

The **SRBEX_DATA_PNP** structure contains the request data for an extended plug and play (PNP) SRB.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypePnp**.

### `Length`

Length of the data in this structure starting with the **PnPSubFunction** member. Set to SRBEX_DATA_PNP_LENGTH.

### `PnPSubFunction`

This member is not currently used. Set to 0.

### `Reserved`

This member is reserved. Set to 0.

### `PnPAction`

The plug and play action to perform. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| **StorStartDevice**<br><br>0x00 | Start the device. |
| **StorRemoveDevice**<br><br>0x02 | Remove the device. |
| **StorStopDevice**<br><br>0x04 | Stop the device. |
| **StorQueryCapabilities**<br><br>0x09 | Query the capabilities of the device. |
| **StorQueryResourceRequirements**<br><br>0x0B | Query the resource requirements for the device. |
| **StorFilterResourceRequirements**<br><br>0x0D | Filter the resource requirements for the device. |
| **StorSupriseRemoval**<br><br>0x17 | Surprise Removal of the device. This value is available starting with Windows 7. |

### `SrbPnPFlags`

Indicates that the PNP request is for the adapter if SRB_PNP_FLAGS_ADAPTER_REQUEST is set and that storage device address is reserved. Otherwise, *SrbPnPFlags* will be **NULL**, indicating that the request is for the storage device specified by an address at **AddressOffset** in the [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block) structure.

### `Reserved1`

This member is reserved. Set to 0.

## See also

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)