# AtaPortInitializeQueueTag function

## Description

The **AtaPortInitializeQueueTag** routine initializes the queue tag list for the specified device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension`

A pointer to the channel extension.

### `TargetId` [in]

Specifies the target identifier of the device.

### `Lun` [in]

Specifies the logical unit number (LUN) of the device.

### `MaxQueueTag` [in]

Specifies the maximum allowed value for the queue tag.

## Return value

**AtaPortInitializeQueueTag** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**.

## Remarks

The miniport driver should call **AtaPortInitializeQueueTag** before it uses [AtaPortAllocateQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportallocatequeuetag) and [AtaPortReleaseQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreleasequeuetag) to allocate and release queue tags respectively.

The values in the *TargetId* and *Lun* parameters specify the device to which the queue tag belongs. To generate channel specific queue tags, the miniport driver should set the *TargetId* and *Lun* parameters to IDE_UNTAGGED.

## See also

[AtaPortAllocateQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportallocatequeuetag)

[AtaPortReleaseQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreleasequeuetag)