# StorPortGetDataInBufferSystemAddress function

## Description

Returns the system address for the input data buffer of a SCSI request block (SRB).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

The request block to containing the input data buffer.

### `SystemAddress` [out]

A pointer to an address value to receive the system address for the input data buffer in *Srb*.

## Return value

A status value indicating the result of the notification. This can be one of these values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | A system address of the input data buffer for *Srb* was successfully returned. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer value in *SystemAddress* is NULL. |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL is > DISPATCH_LEVEL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | A system address can't be assigned. |

## See also

[StorPortGetDataInBufferMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbuffermdl)

[StorPortGetDataInBufferScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbufferscattergatherlist)