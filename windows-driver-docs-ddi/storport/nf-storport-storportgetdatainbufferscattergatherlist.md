# StorPortGetDataInBufferScatterGatherList function

## Description

Returns the scatter-gather list associated with the input data buffer of a SCSI request block (SRB).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

The request block to containing the input data buffer for the scatter-gather list.

### `SgList` [out]

A pointer to a scatter-gather list structure address to receive the scatter-gather list for the input data buffer in *Srb*.

## Return value

A status value indicating the result of the notification. This can be one of these values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The scatter-gather list for *Srb* was successfully returned. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer value in *SgList* is NULL. |

## See also

[StorPortGetDataInBufferMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbuffermdl)

[StorPortGetDataInBufferSystemAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbuffersystemaddress)