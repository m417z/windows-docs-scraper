# StorPortGetOriginalMdl function

## Description

The **StorPortGetOriginalMdl** routine returns the MDL associated with the given SRB.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

A pointer to a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) structure.

### `Mdl` [out]

A pointer to receive the MDL.

## Return value

StorPortGetOriginalMdl returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the MDL was obtained successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer in *Mdl* receiving the SRB's MDL is **NULL**. |

## Remarks

Starting in Windows 8, the *Srb* parameter may point to either [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[StorPortGetSystemAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetsystemaddress)