# ScsiPortGetSrb function

## Description

The **ScsiPortGetSrb** routine returns a pointer to an active SCSI request for a particular logical unit.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the bus.

### `Lun` [in]

Identifies the logical unit number of the target device.

### `QueueTag` [in]

Specifies the queue tag if the miniport driver handles tagged requests; SP_UNTAGGED indicates that the request is not tagged.

## Return value

**ScsiPortGetSrb** returns a pointer to a request for the specified logical unit. If there is no outstanding request for the given peripheral or if the *QueueTag* value is invalid, it returns **NULL**.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)