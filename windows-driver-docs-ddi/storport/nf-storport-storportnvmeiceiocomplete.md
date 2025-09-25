## Description

The **StorPortNvmeIceIoComplete** function signals the completion of an NVMe I/O operation that was initiated by a previous call to [**StorPortNvmeIceIoStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnvmeiceiostart).

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb`

[in] A pointer to a SCSI request block. This structure represents a single I/O request.

## Return value

**StorPortNvmeIceIoComplete** returns STOR_STATUS_SUCCESS if the operation is successful. Otherwise, it returns a STOR_STATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | This function isn't implemented on the active operating system. |
| STOR_STATUS_INVALID_PARAMETER | One of the parameters is invalid. |

## Remarks

## See also

[**StorPortNvmeIceIoStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnvmeiceiostart)