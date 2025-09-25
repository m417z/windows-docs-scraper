# StorPortGetDataInBufferMdl function

## Description

Returns an MDL associated with the input data buffer of a SCSI request block (SRB).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

The request block to containing the data described by the MDL pointed to by *Mdl*.

### `Mdl` [out]

A pointer to an MDL address to receive the MDL for *Srb*.

## Return value

A status value indicating the result of the notification. This can be one of these values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The MDL for *Srb* was successfully returned. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer value in *Mdl* is NULL. |

## See also

[StorPortGetDataInBufferScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbufferscattergatherlist)

[StorPortGetDataInBufferSystemAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbuffersystemaddress)