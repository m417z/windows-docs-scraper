# AtaPortReleaseQueueTag function

## Description

The **AtaPortReleaseQueueTag** routine releases the specified queue tag.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension`

A pointer to the channel extension.

### `TargetId` [in]

Specifies the target identifier of the device.

### `Lun` [in]

Specifies the logical unit number of the device.

### `QueueTag` [in]

Specifies the queue tag to be freed.

## Remarks

The miniport driver should call **AtaPortReleaseQueueTag** to free allocated queue tags by using [AtaPortAllocateQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportallocatequeuetag).

## See also

[AtaPortAllocateQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportallocatequeuetag)

[AtaPortInitializeQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializequeuetag)