# AtaPortAllocateQueueTag function

## Description

The **AtaPortAllocateQueueTag** routine returns a queue tag for the specified device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension`

A pointer to the channel extension.

### `TargetId` [in]

Specifies the target identifier of the device.

### `Lun` [in]

Specifies the logical unit number (LUN) of the device.

## Return value

**AtaPortAllocateQueueTag** returns a valid queue tag if one can be allocated. A value of 0 is returned if a queue tag could not be allocated.

## Remarks

The **AtaPortAllocateQueueTag** routine allocates either a per device queue tag or a per channel queue tag. To generate a per channel queue tag, the miniport driver should set the *TargetId* and *Lun* parameters to IDE_UNTAGGED.

## See also

[AtaPortInitializeQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializequeuetag)

[AtaPortReleaseQueueTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreleasequeuetag)