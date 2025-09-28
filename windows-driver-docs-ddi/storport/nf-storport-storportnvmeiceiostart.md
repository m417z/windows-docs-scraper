## Description

The **StorPortNvmeIceIoStart** function initiates an NVMe ICE (Inline Cryptographic Engine) I/O operation.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension. This is a per HBA (Host Bus Adapter) context area provided by the miniport driver. The miniport driver can store HBA-specific information here.

### `Srb`

[in] A pointer to a [SCSI request block](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_scsi_request_block). This structure represents a single I/O request.

### `LbaCount`

[in] The number of logical block addresses (LBAs) to be transferred.

### `PrpCount`

[in] The number of physical region pages (PRPs) to be transferred.

### `Prp1`

[in/out] A pointer to the first PRP, used in NVMe to describe the physical memory locations involved in the data transfer.

### `Prp2`

[in/out] A pointer to the second PRP, used in NVMe to describe the physical memory locations involved in the data transfer.

### `PrpList`

[in/out] A pointer to a list of additional PRPs.

## Return value

**StorPortNvmeIceIoStart** returns STOR_STATUS_SUCCESS if the operation is successful. Otherwise, it returns a STOR_STATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | This function isn't implemented on the active operating system. |
| STOR_STATUS_INVALID_PARAMETER | One of the parameters is invalid. |

## Remarks

## See also

[**StorPortNvmeIceIoComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnvmeiceiocomplete)